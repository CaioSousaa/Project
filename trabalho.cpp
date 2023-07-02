#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const int lines = 15;

string nome_remedio[lines] = {};
string tipo[lines] = {}; //comprimido ou liquido
string finalidade[lines] = {}; //pra que serve
string generico[lines] = {};
string id_remedio[lines] = {};

void registe() {
    cin.ignore();

    cout << "Digite o Nome do Remédio: " << endl;
    string nome;
    getline(cin, nome);

    cout << "Digite o Tipo do Remédio: " << endl;
    string tip;
    getline(cin, tip);

    cout << "Digite a Finalidade do Remédio: " << endl;
    string fina;
    getline(cin, fina);

    cout << "Digite a Procedência do remédio: " << endl;
    string gen;
    getline(cin, gen);

    cout << "Digite o id do remedio" << endl;
    string id;
    getline(cin, id);
    
    for (int i = 0; i < lines; i++) {
        if (id_remedio[i].empty()) {
            nome_remedio[i] = nome;
            tipo[i] = tip;
            finalidade[i] = fina;
            generico[i] = gen;
            id_remedio[i] = id;
            break;
        }
    }
}

void update(string x) {
    string nome;
    string tip;
    string fina;
    string gen;

    int leitura;

    cout << "_______________________" << endl;
    cout << "Digite 1 para alterar o nome do remédio" << endl;
    cout << "Digite 2 para alterar o tipo do remédio" << endl;
    cout << "Digite 3 para alterar a finalidade do remédio" << endl;
    cout << "Digite 4 para alterar a procedência do remédio" << endl;
    cout << "_______________________" << endl;

    cin >> leitura;

    switch (leitura) {
        case 1:
            for (int i = 0; i < lines; i++) {
                if (id_remedio[i] == x) {
                    cout << "Informe o novo nome: " << endl;
                    cin.ignore();
                    getline(cin, nome);
                    nome_remedio[i] = nome;
                    break;
                }
            }
            break;
        case 2:
            for (int i = 0; i < lines; i++) {
                if (id_remedio[i] == x) {
                    cout << "Informe o novo tipo: " << endl;
                    cin.ignore();
                    getline(cin, tip);
                    tipo[i] = tip;
                    break;
                }
            }
            break;
        case 3:
            for (int i = 0; i < lines; i++) {
                if (id_remedio[i] == x) {
                    cout << "Informe a nova finalidade: " << endl;
                    cin.ignore();
                    getline(cin, fina);
                    finalidade[i] = fina;
                    break;
                }
            }
            break;
        case 4:
            for (int i = 0; i < lines; i++) {
                if (id_remedio[i] == x) {
                    cout << "Informe a procedência: " << endl;
                    cin.ignore();
                    getline(cin, gen);
                    generico[i] = gen;
                    break;
                }
            }
            break;
    }
}

void search(string x) {
    cout << left << setw(20) << "Nome do Remédio";
    cout << left << setw(15) << "ID do Remédio";
    cout << left << setw(15) << "Tipo";
    cout << left << setw(15) << "Finalidade";
    cout << left << setw(15) << "Veracidade" << endl;

    for (int i = 0; i < lines; i++) {
        if (id_remedio[i] == x) {
            cout << left << setw(20) << nome_remedio[i];
            cout << left << setw(15) << id_remedio[i];
            cout << left << setw(15) << tipo[i];
            cout << left << setw(15) << finalidade[i];
            cout << left << setw(15) << generico[i] << endl;
        }
    }
}

void delet(string x) {

    for (int i = 0; i < lines; i++) {
        if (id_remedio[i] == x) {
            id_remedio[i] = " ";
            tipo[i] = " ";
            finalidade[i] = " ";
            generico[i] = " ";
            break;
        }
    }
} 

void table(string x) {
    cout << left << setw(20) << "Nome do Remédio" << "|";
    cout << left << setw(15) << "ID do Remédio" << "|";
    cout << left << setw(15) << "Tipo" << "|";
    cout << left << setw(15) << "Finalidade" << "|";
    cout << left << setw(15) << "Veracidade" << "|" << endl;

    for (int i = 0; i < lines; i++) {
        if (id_remedio[i] != " ") {
            cout << left << setw(20) << nome_remedio[i] << "|";
            cout << left << setw(15) << id_remedio[i] << "|";
            cout << left << setw(15) << tipo[i] << "|";
            cout << left << setw(15) << finalidade[i] << "|";
            cout << left << setw(15) << generico[i] << "|" << endl;
        }
    }
}

int main() {
    int leitura;
    do {
        cout << "_______________________" << endl;

        cout << "Digite 1 para cadastrar um novo remédio" << endl;
        cout << "Digite 2 para atualizar informações do remédio" << endl;
        cout << "Digite 3 para pesquisar o remédio" << endl;
        cout << "Digite 4 para deletar o remédio" << endl;
        cout << "Digite 5 para mostrar remédios" << endl;

        cout << "_______________________" << endl;
        cin >> leitura;

        string ID;

        switch (leitura) {
            case 1:
                registe();
                system("CLS");
                break;
            case 2:
                cout << "Digite o ID do remédio: " << endl;
                cin >> ID;
                update(ID);
                system("CLS");
                break;
            case 3:
                cout << "Digite o ID do remédio: " << endl;
                cin >> ID;
                search(ID);
                break;
            case 4:
                cout << "Digite o ID do remédio: " << endl;
                cin >> ID;
                delet(ID);
                system("CLS");
                break;
            case 5:
                table(ID);
                break;
        }
    } while (leitura != 6);

    return 0;
}