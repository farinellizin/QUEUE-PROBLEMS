#include "dynamicqueue.hpp"
using namespace std;

void run() {
    char option;

    do { 
        cout << endl << endl << "-------------------------------------------------------------------------------------";
        cout << endl << endl << "\t\t\t ~ Welcome to the main menu ~" << endl << endl;
        cout << "\t\tA. Two halfs of two Queues;" << endl << "\t\tB. Making index;" << endl;
        cout << "\t\tC. Ordenating by index;" << endl << "\t\tD. Exit;" << endl;
        cout << endl << "\t\t\t- Your option: ";
        cin >> option;
        option = toupper(option);

        if (option == 'A') {
            problem_3_a();
        } else if (option == 'B') {
            Fila f1;
	        Item aux;
 
	        FFVazia(&f1);
	        insertNewValue(&f1, aux); 
            equation(&f1, aux);

	        cout << "\tFila 1" << endl;
	        FImprime(&f1);
        } else if (option == 'C') {
            Fila index, f1, f2, f3;
            Item aux;

        	FFVazia(&index); // Fila que guardará todos os indexadores.

	        FFVazia(&f1);
	        insertNewValue(&f1, aux); //Função para inserir novos valores a fila.
	        equation_c(&index, &f1, aux);  //Calcula a média aritmética dos valores contidos na fila e salva o valor na última posição da fila.

	        FFVazia(&f2);
        	insertNewValue(&f2, aux);
	        equation_c(&index, &f2, aux);

	        FFVazia(&f3);
	        insertNewValue(&f3, aux);
	        equation_c(&index, &f3, aux);

	        cout << "\n\tFila 1" << endl;
	        FImprime(&f1);

	        cout << "\n\tFila 2" << endl;
	        FImprime(&f2);

	        cout << "\n\tFila 3" << endl;
	        FImprime(&f3);
	
	        cout << "\nFila de indexadores" << endl;
	        FImprime(&index);   
        } else {
            cout << "leaving...";
        }
    } while (option != 'D');
}

int main () {
    run();
}