#include <iostream>
#include <cstring>
#include <oci.h>

// Ponteiros globais só para simplificar o exemplo
OCIEnv    *envhp  = nullptr;
OCIError  *errhp  = nullptr;
OCISvcCtx *svchp  = nullptr;
OCIStmt   *stmthp = nullptr;
OCIDefine *def_id = nullptr;
OCIDefine *def_nome = nullptr;
OCIDefine *def_idade = nullptr;

void checkOCIError(sword status, const char* msg) {
    if (status == OCI_SUCCESS) return;

    if (!errhp) {
        std::cerr << "[OCI ERRO] " << msg << " (sem handle de erro)\n";
        exit(1);
    }

    text errbuf[512];
    sb4 errcode = 0;

    if (status == OCI_ERROR || status == OCI_SUCCESS_WITH_INFO) {
        OCIErrorGet(
            errhp,
            1,
            nullptr,
            &errcode,
            errbuf,
            sizeof(errbuf),
            OCI_HTYPE_ERROR
        );
        std::cerr << "[OCI ERRO] " << msg
                  << " (código " << errcode << "): "
                  << errbuf << "\n";
    } else {
        std::cerr << "[OCI ERRO] " << msg << " (status = " << status << ")\n";
    }

    if (status != OCI_SUCCESS && status != OCI_SUCCESS_WITH_INFO) {
        exit(1);
    }
}

int main() {
    // AJUSTE ISSO AQUI PRO SEU XE:
    const char* usuario = "system";
    const char* senha   = "";              // sua senha
    const char* db      = "localhost:1521/XE"; //

    sword status;

    // 1) Criar ambiente OCI
    status = OCIEnvCreate(
        &envhp,
        OCI_THREADED | OCI_OBJECT,
        nullptr, nullptr, nullptr, nullptr,
        0, nullptr
    );
    if (status != OCI_SUCCESS) {
        std::cerr << "Falha ao criar ambiente OCI\n";
        return 1;
    }

    // 2) Handle de erro
    status = OCIHandleAlloc(envhp, (dvoid**)&errhp, OCI_HTYPE_ERROR, 0, nullptr);
    checkOCIError(status, "OCIHandleAlloc(errhp)");

    // 3) Logon simples
    status = OCILogon(
        envhp,
        errhp,
        &svchp,
        (OraText*)usuario,
        (ub4)std::strlen(usuario),
        (OraText*)senha,
        (ub4)std::strlen(senha),
        (OraText*)db,
        (ub4)std::strlen(db)
    );
    checkOCIError(status, "OCILogon");

    std::cout << "Conectado com sucesso ao Oracle!\n";

    // 4) Preparar statement para listar alunos
    const char* sql = "SELECT id, nome, idade FROM Alunos";

    status = OCIHandleAlloc(envhp, (dvoid**)&stmthp, OCI_HTYPE_STMT, 0, nullptr);
    checkOCIError(status, "OCIHandleAlloc(stmthp)");

    status = OCIStmtPrepare(
        stmthp,
        errhp,
        (const OraText*)sql,
        (ub4)std::strlen(sql),
        OCI_NTV_SYNTAX,
        OCI_DEFAULT
    );
    checkOCIError(status, "OCIStmtPrepare");

    // 5) Variáveis de saída
    int   id = 0;
    int   idade = 0;
    char  nome[101];  // buffer pra nome (até 100 chars + '\0')
    std::memset(nome, 0, sizeof(nome));

    // 5.1) Bind da coluna 1: id
    status = OCIDefineByPos(
        stmthp,
        &def_id,
        errhp,
        1, // coluna 1 -> id
        (dvoid*)&id,
        sizeof(id),
        SQLT_INT,
        nullptr, nullptr, nullptr,
        OCI_DEFAULT
    );
    checkOCIError(status, "OCIDefineByPos(id)");

    // 5.2) Bind da coluna 2: nome
    status = OCIDefineByPos(
        stmthp,
        &def_nome,
        errhp,
        2, // coluna 2 -> nome
        (dvoid*)nome,
        sizeof(nome),
        SQLT_CHR,  // tipo texto
        nullptr, nullptr, nullptr,
        OCI_DEFAULT
    );
    checkOCIError(status, "OCIDefineByPos(nome)");

    // 5.3) Bind da coluna 3: idade
    status = OCIDefineByPos(
        stmthp,
        &def_idade,
        errhp,
        3, // coluna 3 -> idade
        (dvoid*)&idade,
        sizeof(idade),
        SQLT_INT,
        nullptr, nullptr, nullptr,
        OCI_DEFAULT
    );
    checkOCIError(status, "OCIDefineByPos(idade)");

    // 6) Executar (sem iterações ainda, vamos usar fetch)
    status = OCIStmtExecute(
        svchp,
        stmthp,
        errhp,
        0, // 0 -> vamos buscar linha a linha com OCIStmtFetch2
        0,
        nullptr, nullptr,
        OCI_DEFAULT
    );
    checkOCIError(status, "OCIStmtExecute");

    // 7) Loop de fetch de todas as linhas
    std::cout << "\n== Lista de alunos ==\n";

    while (true) {
        status = OCIStmtFetch2(
            stmthp,
            errhp,
            1,              // buscar 1 linha por vez
            OCI_FETCH_NEXT,
            0,
            OCI_DEFAULT
        );

        if (status == OCI_NO_DATA) {
            // acabou as linhas
            break;
        }

        checkOCIError(status, "OCIStmtFetch2");

        // Só pra garantir que nome é string terminada em '\0'
        nome[100] = '\0';

        std::cout << "ID: " << id
                  << " | Nome: " << nome
                  << " | Idade: " << idade << "\n";
    }

    // 8) Limpar
    if (stmthp) OCIHandleFree(stmthp, OCI_HTYPE_STMT);
    if (svchp)  OCILogoff(svchp, errhp);
    if (errhp)  OCIHandleFree(errhp, OCI_HTYPE_ERROR);
    if (envhp)  OCIHandleFree(envhp, OCI_HTYPE_ENV);

    return 0;
}
