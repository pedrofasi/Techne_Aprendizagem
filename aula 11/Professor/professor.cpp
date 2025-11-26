// Aula11.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
 
#include <iostream>
#include <oci.h>
 
#pragma comment(lib, "oci.lib")
 
using namespace std;
 
OCIEnv*    g_env = nullptr;
OCIError*  g_err = nullptr;
OCISvcCtx*  g_svc = nullptr;
 
 
void checkerr(OCIError* errhp, sword status) {
    if (status != OCI_SUCCESS) {
        text errbuf[512];
        sb4 errcode = 0;
        OCIErrorGet(errhp, 1, nullptr, &errcode, errbuf,
            sizeof(errbuf), OCI_HTYPE_ERROR);
 
        cout << "Erro OCI (" << errcode << "): " << errbuf << endl;
 
    }
}
 
void CconectarOracle()
{
    //1. Iniciar OCI
    checkerr(nullptr, OCIEnvCreate(&g_env, OCI_DEFAULT, 0, 0, 0, 0, 0, 0));
   
    //2. Aloca um handle de erro
    OCIHandleAlloc(g_env, (void**)&g_err, OCI_HTYPE_ERROR, 0, 0);
 
    //3. Criar o contexto (conexão)
    OCIHandleAlloc(g_env, (void**)&g_svc, OCI_HTYPE_SVCCTX, 0, 0);
 
    //4. Login
    checkerr(
        g_err,
        OCILogon(
            g_env, g_err, &g_svc,
            (OraText*)"system", 6, //usuario
            (OraText*)"", 8, //senha
            (OraText*)"localhost/XEPDB1", 17 //string de conexão
        )
    );
    cout << "Conetado ao Oracle com sucesso!" << endl;
 
    // // 5. Preparar o SQL
 
    // OCIStmt* stmt = nullptr;
    // OCIHandleAlloc(env, (void**)&stmt, OCI_HTYPE_STMT, 0, 0);
 
    // const char* sql =  "SELECT 'HELLO OCI' FROM dual";
 
    // checkerr(err, OCIStmtPrepare(stmt, err,
    // (OraText*)sql, (ub4)strlen(sql),
    // OCI_NTV_SYNTAX, OCI_DEFAULT));
 
    // // 6. Definir a saída
    // char resultado[50]
    // OCIDefine* def = nullptr
    // checkerr(err,
    //     OCIDefineByPos(stmt, &def, err,
    //                     1, resultado, sizeof(resultado),
    //                     SQLT_STR, nullptr, nullptr, nullptr, OCI_DEFAULT));
 
    // //7. Executar o SQL
    // checkerr(err, OCIStmtExecute(
    //     svc, stmt, err, 0,0, nullptr, nullptr, OCI_DEFAULT
    // ));
 
    // //8. Loop de leitura
    // while(OCIStmtFetch2(stmt, err,1, OCI_DEFAULT, 0, OCI_DEFAULT)!= OCI_NO_DATA ){
    //     cout << "Resultado : " << resultado << endl
    // }
 
    // // 9. Finaliza a sessão
    // OCILogoff(svc, err)
    // cout << "Sessão Encerrada" << endl;
 
 
}
void desconectarOracle(){
    if(g_svc != nullptr && g_err != nullptr){
        OCILogoff(g_svc, g_err);
        cout << "Desconectado do Oracle com sucesso!" << endl;
    }
}
 
void inserirAluno(const string& nome, int idade){
    OCIStmt* stmt = nullptr;
    OCIBind* bndNome = nullptr;
    OCIBind* bndIdade = nullptr;
 
    const char* sql = "INSERT INTO ALUNOS (NOME, IDADE) VALUES (:nome, :idade)";
 
    checkerr(g_err,
        OCIStmtPrepare(stmt, g_err,
            (OraText*)sql, (ub4)strlen(sql),
            OCI_NTV_SYNTAX, OCI_DEFAULT)
    );
 
    //Buffer para nome
    char nomeBuf[101];
    memset(nomeBuf, 0, sizeof(nomeBuf));
    strncpy_s(nomeBuf, sizeof(nomeBuf), nome.c_str(), sizeof(nomeBuf) - 1);
 
    //Bind do Nome
    checkerr(g_err,
        OCIBindByName(stmt, &bndNome, g_err,
            (OraText*)":nome", -1,
            (dvoid*)nomeBuf, sizeof(nomeBuf),
            SQLT_STR, nullptr, nullptr, nullptr, 0, nullptr, OCI_DEFAULT)
    );
    //Bind da Idade
    sb4 idadeValor = idade;
    checkerr(g_err,
        OCIBindByName(stmt, &bndIdade, g_err,
            (OraText*)":idade", -1,
            (dvoid*)&idadeValor, sizeof(idadeValor),
            SQLT_INT, nullptr, nullptr, nullptr, 0, nullptr, OCI_DEFAULT)
    );
    //Executar com commit
    checkerr(g_err,
        OCIStmtExecute(g_svc, stmt, g_err, 1, 0, nullptr, nullptr, OCI_COMMIT_ON_SUCCESS)
    );
 
    cout << "Aluno inserido com sucesso: " << nome << ", Idade: " << idade << endl;
 
    //Liberar stmt
    OCIHandleFree(stmt, OCI_HTYPE_STMT);
}