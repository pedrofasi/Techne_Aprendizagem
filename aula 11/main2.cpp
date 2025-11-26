#include <iostream>
#include <string>
#include <occi.h>

using namespace oracle::occi;
using namespace std;

int main() {
    // Ajuste aqui para seu ambiente:
    string usuario = "system";
    string senha   = "";        // senha do usuário
    string connStr = "localhost:1521/XE"; // XE 21c padrão

    Environment *env = nullptr;
    Connection  *conn = nullptr;

    try {
        // Cria ambiente OCCI
        env = Environment::createEnvironment(Environment::DEFAULT);

        // Abre conexão
        conn = env->createConnection(usuario, senha, connStr);
        cout << "Conectado ao Oracle com OCCI!" << endl;

        // SQL para buscar id, nome, idade
        // Ajuste o nome da tabela/colunas se forem diferentes
        string sql = "SELECT id, nome, idade FROM alunos ORDER BY id";

        Statement *stmt = conn->createStatement(sql);
        ResultSet *rs   = stmt->executeQuery();

        cout << "ID\tIDADE\tNOME" << endl;
        cout << "----------------------------" << endl;

        while (rs->next()) {
            int id       = rs->getInt(1);      // coluna 1: id
            string nome  = rs->getString(2);   // coluna 2: nome
            int idade    = rs->getInt(3);      // coluna 3: idade

            cout << id << "\t" << idade << "\t" << nome << endl;
        }

        // Limpeza
        stmt->closeResultSet(rs);
        conn->terminateStatement(stmt);
        env->terminateConnection(conn);
        Environment::terminateEnvironment(env);

    } catch (SQLException &ex) {
        cerr << "Erro Oracle (código " << ex.getErrorCode()
             << "): " << ex.getMessage() << endl;
        if (conn) {
            env->terminateConnection(conn);
        }
        if (env) {
            Environment::terminateEnvironment(env);
        }
        return 1;
    }

    return 0;
}
