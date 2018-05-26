/*
 * main.cpp
 *
 *  Created on: 18/05/2018
 *      Author: aet
 */

#include <iostream>
#include "student.h"

using namespace std;

int main(){
	Student student1;
	Student student2("Pedro"); // @suppress("Ambiguous problem")
	const Student student3("João", 30, 2017); //constant student that cannot be changed // @suppress("Ambiguous problem")
	Student student4("João", 30); // @suppress("Ambiguous problem")
	student1.setNumber(-1); //Não altera mantém o valor original da construção
	//cout << student1.number; //Erro: Não permite aceder a um membro privado de fora da classe
	//student1.number =10;
	cout << student1.getNumber();
	student2.setNumber(30); //Altera porque é um número válido, de acordo com a validação da função membro
	cout << student2.getNumber();
    //student3.setNumber(10); //Porque dá erro?
	Student student5("António"); //outros parâmetros da função são os por omissão // @suppress("Ambiguous problem")

	cout << student1.getSetNumber();
	cout << "After invoking a function which returns a reference... ";
	student1.getSetNumber()=100;
	cout << student1.getSetNumber() << endl;
	cout << "Please verify the order by which all stdudents are destroyed...";

	Student student6("Ana",12345, 2018, 23,2,2018);
	student6.show();


	return 0;
}
