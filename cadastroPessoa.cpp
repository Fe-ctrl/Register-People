#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

void cadPessoa() {
  ofstream arq;
  arq.open("pessoas.dat", ios::app);
  if (!arq.is_open()) {
    cout << "Erro na abertura do arquivo de pessoas\n";
    return;
  }
  string rg, nome, email, telefone, rua, numero, bairro, cidade, cep;
  char cont = 's';
  while (cont == 's') {
    system("cls");
    cout << "Cadastro de Pessoas\n\n";
    cout << "RG............: ";
    cin >> rg;
    cout << "Nome..........: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Email.........: ";
    getline(cin, email);
    cout << "Telefone......: ";
    getline(cin, telefone);
    cout << "Rua...........: ";
    getline(cin, rua);
    cout << "Número........: ";
    getline(cin, numero);
    cout << "Bairro........: ";
    getline(cin, bairro);
    cout << "Cidade........: ";
    getline(cin, cidade);
    cout << "CEP...........: ";
    getline(cin, cep);

    arq << rg << endl;
    arq << nome << endl;
    arq << email << endl;
    arq << telefone << endl;
    arq << rua << endl;
    arq << numero << endl;
    arq << bairro << endl;
    arq << cidade << endl;
    arq << cep << endl;

    cout << endl << "Deseja cadastrar outra pessoa (s/n): ";
    cin >> cont;
    cont = tolower(cont);
  }
  arq.close();
}

void listaPessoas() {
  ifstream arq;
  arq.open("pessoas.dat", ios::in);
  if (!arq.is_open()) {
    cout << "Erro na abertura do arquivo de pessoas\n";
    return;
  }
  string rg, nome, email, telefone, rua, numero, bairro, cidade, cep;
  system("cls");
  cout << "Listagem de Pessoas\n\n";
  cout << "+--------+----------------------+---------------------+---------------+---------------------+" << endl;
  cout << "|   RG   |         Nome         |       Email         |    Telefone   |        Cidade      |" << endl;
  cout << "+--------+----------------------+---------------------+---------------+---------------------+" << endl;
  
  while (getline(arq, rg)) {
    getline(arq, nome);
    getline(arq, email);
    getline(arq, telefone);
    getline(arq, rua);
    getline(arq, numero);
    getline(arq, bairro);
    getline(arq, cidade);
    getline(arq, cep);

    cout << "| " << setw(6) << rg << " | " << left << setw(20) << nome << " | " << setw(19) << email 
         << " | " << setw(13) << telefone << " | " << setw(19) << cidade << " |" << endl;
  }
  cout << "+--------+----------------------+---------------------+---------------+---------------------+" << endl;
  arq.close();
}

int main() {
  int op = 1;
  while (op) {
    system("cls");
    cout << "+---------------------+" << endl;
    cout << "| 1 - Cadastrar       |" << endl;
    cout << "+---------------------+" << endl;
    cout << "| 2 - Listar          |" << endl;
    cout << "+---------------------+" << endl;
    cout << "| 0 - Sair            |" << endl;
    cout << "+---------------------+" << endl;
    cout << "Opcao: ";
    cin >> op;
    if (op == 1) {
      cadPessoa();
    }

    if (op == 2) {
      listaPessoas();
      cin.ignore();
      cout << "Pressione Enter para continuar ";
      cin.get();
    }
  }
  return 0;
}
