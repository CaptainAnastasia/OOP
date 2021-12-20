#include <iostream>
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
#include "Summator.h"
#include "Substractor.h"
using namespace std;


int main()
{
    ExpressionEvaluator* ptrs[3];


    ptrs[0] = new CustomExpressionEvaluator();
    ptrs[0]->setOperand(0, 15);
    ptrs[0]->setOperand(1, 10);
    ptrs[0]->setOperand(2, -3);
    ptrs[0]->setOperand(3, 12);
    ptrs[0]->setOperand(4, -6.5);




    ptrs[1] = new Summator();
    double ops_sum[] = { 15, -3.5, 10.5, -2.1, 3.3, 4, 6.3 };
    ptrs[1]->setOperands(ops_sum, 7);



    ptrs[2] = new Substractor();
    double ops_sub[] = { 1.5, 4, -2.5 };
    ptrs[2]->setOperands(ops_sub, 3);

    for (int i = 0; i < 3; ++i) {
        ptrs[i]->logToScreen();
        cout << endl;
        ptrs[i]->logToFile("output.txt");
    }


    for (int i = 0; i < 3; ++i) {
        CustomExpressionEvaluator* custom_expression = dynamic_cast<CustomExpressionEvaluator*>(ptrs[i]);
        if (custom_expression) {
            custom_expression->shuffle();
            custom_expression->logToScreen();
        }
        
    }

}

