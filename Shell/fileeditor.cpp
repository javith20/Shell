#include "fileeditor.h"
fileEditor::fileEditor()
{

}
int fileEditor::createFile(string name)
{
    ofstream fs(name);
    fs.close();
    return 0;
}

int fileEditor::readFile(string name)
{
    cout << "Ingresa el nombre del archivo que quieres leer(sin el .txt): ";
    cin.ignore();
    getline(cin, contenido2);
    contenido2 += ".txt";
    ifstream fs(contenido2.c_str(), ios:: in );
    char linea[128];
    long contador = 0L;
    if (fs.fail())
      cerr << "El fichero no existe" << endl;
    else
      while (!fs.eof()) {
        fs.getline(linea, sizeof(linea));
        cout << linea << endl;
        if ((++contador % 24) == 0) {
          cout << "continuar...";
          cin.get();
        }
      }
    fs.close();
    system("pause");
    return 0;
}

int fileEditor::modifyFile()
{
    cout << "Ingresa el nombre del archivo que quieres modificar(sin el .txt): ";

           getline(cin, contenido2);
           contenido2 += ".txt";
           cout << "Ingresa el NUEVO contenido del archivo: ";
           getline(cin, contenido);
           ofstream fs(contenido2.c_str(), ios::out);
           fs << contenido << endl;
           fs.close();
           cout << "El archivo ha sido modificado correctamente" << endl;
           system("pause");
           return 0;
}
void fileEditor::presentaMenuGeneral() {

  int opcion;
  do {
    system("cls");
    cout << "Menu principal" << endl;
    cout << "========================" << endl;
    cout << "[1]Crear archivo de texto" << endl;
    cout << "[2]Abrir archivo de texto" << endl;
    cout << "[3]Modificar archivo de texto" << endl;
    cout << "[0]Salir del programa" << endl;
    cout << "========================" << endl;
    cout << "Ingresa la opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 0:
      break;
    case 1:
      {
        createFile("");
      }
    case 2:
      {
        readFile("");
      }
    case 3:
      {
        modifyFile();
      }
    default:
      cout << "\nEl numero de opcion escrito no es valido\n" << endl;
      system("pause");
    }
  } while (opcion != 0);
}
