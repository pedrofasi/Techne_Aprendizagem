// SRP (Single Responsibility Principle)
// Gerenciador de Usuários: Crie uma classe UsuarioService que seja responsável por cadastrar usuários,
//  enviar e-mail de boas-vindas e gerar um relatório com todos os usuários cadastrados. Refatore essa 
//  classe para seguir o SRP, separando as responsabilidades em classes distintas 
// (ex.: cadastro/gerenciamento, envio de e-mail, geração de relatório).
 



#include <iostream>
#include <vector>
#include <string>

class UsuarioRepository{
public:
    std::vector<std::string> usuarios;

    void adicionarUsuario(const std::string& nome) {
        usuarios.push_back(nome);
    }

    const std::vector<std::string>& getUsuarios() const {
        return usuarios;
    }
};


class EmailService {
    public:
    void enviarEmailBoasVindas(const std::string& nome) {
        std::cout << "Enviando e-mail de boas-vindas para " << nome << std::endl;
    }
    void enviarEmailCompra() {
        std::cout << "Enviando e-mail de confirmação de compra" << std::endl;
    }
};

class RelatorioService {
public:
    void gerarRelatorio(const std::vector<std::string>& usuarios) {
        std::cout << "Relatório de Usuários Cadastrados:" << std::endl;
        for (const auto& usuario : usuarios) {
            std::cout << "- " << usuario << std::endl;
        }
    }
};

class UsuarioService {
    private:
    UsuarioRepository& usuarioRepo;
    EmailService& emailService;
    RelatorioService& relatorioService;
    public:

    UsuarioService(UsuarioRepository& repo, EmailService& emailSvc, RelatorioService& relatorioSvc)
        : usuarioRepo(repo), emailService(emailSvc), relatorioService(relatorioSvc) {}

    void cadastrar(){
        std::string nome;
        std::cout << "Digite o nome do usuário: ";
        std::cin >> nome;
        usuarioRepo.adicionarUsuario(nome);
        emailService.enviarEmailBoasVindas(nome);
    }

    void gerarRelatorio(){
        relatorioService.gerarRelatorio(usuarioRepo.getUsuarios());
    }
};

int main(){
    //gerar um menu para cadastrar usuarios e gerar relatorio
    UsuarioRepository usuarioRepo;
    EmailService emailService;
    RelatorioService relatorioService;
    UsuarioService usuarioService{usuarioRepo, emailService, relatorioService}; 

    int opcao;
    do {
        std::cout << "1. Cadastrar Usuário" << std::endl;
        std::cout << "2. Gerar Relatório de Usuários" << std::endl;
        std::cout << "3. Sair" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                usuarioService.cadastrar();
                break;
            case 2:
                usuarioService.gerarRelatorio();
                break;
            case 3:
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
        }
    } while (opcao != 3);

   



}