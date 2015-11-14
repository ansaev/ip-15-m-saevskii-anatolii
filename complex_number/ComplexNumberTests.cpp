//
// Created by ansaev on 21.09.15.
//

#include "ComplexNumber.cpp"
#include <string>
#include <iostream>

class ComplexNumberTests{
private:
    string msg;
    bool failed;
public:
    ComplexNumberTests(){
        msg = string();
        failed = false;
    }
    bool run(){
        if (!construct_tests()){
            msg += "Construction tests have been failed!\n";
            failed = true;
        } else{
            msg += "Construction tests have been PASSED!\n";
        }
        if (!toString_tests()){
            msg += "To string tests have been failed!\n";
            failed = true;
        } else{
            msg += "To string tests have been PASSED!\n";
        }
        if (!summ_tests()){
            msg += "Summ tests have been failed!\n";
            failed = true;
        } else{
            msg += "Summ tests have been PASSED!\n";
        }

        if (!subtract_tests()){
            msg += "Substract tests have been failed!\n";
            failed = true;
        } else{
            msg += "Substract tests have been PASSED!\n";
        }
        if (!divide_tests()){
            msg += "Divide tests have been failed!\n";
            failed = true;
        } else{
            msg += "Divide tests have been PASSED!\n";
        }

        if (!multiply_tests()){
            msg += "Multimply tests have been failed!\n";
            failed = true;
        } else{
            msg += "Multimply tests have been PASSED!\n";
        }

        if (!complex_tests()){
            msg += "Complex tests have been failed!\n";
            failed = true;
        } else{
            msg += "Complex tests have been PASSED!\n";
        }

        if(failed){
            msg = "Some test have been failed! A lot of work to do!!!\n" + msg;
            cout << msg << endl;
            return false;
        }
        msg = "All test have been passed! Congratulations!!!\n" + msg;
        cout << msg << endl;
        return true;
    };
    bool construct_tests(){

        for (int i = 0; i <1000; ++i) {
            double x = ((double)rand()/(double)rand());
            double j = ((double)rand()/(double)rand());
            //cout << to_string(x) + " " + to_string(j) + "\n" << endl;
            if (!construct_test(x,j,x,j)) {
                return false;
            }
        }
        return true;

    };
    bool construct_test(double x, double i, double rez_x, double rez_i){
        ComplexNumber *a = new ComplexNumber(x,i);
        bool rez = ((a->getReal() == rez_x) and (a->getIm() == rez_i));
        delete(a);
        return  rez;
    };

    bool toString_tests(){
        return true;
    };

    bool summ_tests(){
        bool passed = true;
        double a[2] = {0.0,0.0};
        double b[2] = {0.0,0.0};
        double rez[2] = {0.0,0.0};
        a[0] = 5.5; a[1] = 12.4; rez[0] = 5.5; rez[1] = 12.4;
        passed = passed and summ_test(a,b,rez);
        a[0] = 5.5; a[1] = 12.4; b[0] = 1.0; b[1] = 3.0; rez[0] = 6.5; rez[1] = 15.4;
        passed = passed and summ_test(a,b,rez);
        return passed;
    };
    bool summ_test(double a[], double b[], double rez[]){

        ComplexNumber *n1 = new ComplexNumber(a[0],a[1]);
        ComplexNumber *n2 = new ComplexNumber(b[0],b[1]);
        ComplexNumber *ans = new ComplexNumber(0.0,0.2);
        *ans = *n1+ *n2;
        bool result = (ans->getReal() == rez[0]) and (ans->getIm() == rez[1]);
        delete(n1,n2,ans);
        return (result);
    };

    bool subtract_tests(){
        bool passed = true;
        double a[2] = {0.0,0.0};
        double b[2] = {0.0,0.0};
        double rez[2] = {0.0,0.0};
        a[0] = 5.5; a[1] = 12.4; rez[0] = 5.5; rez[1] = 12.4;
        passed = passed and subtract_test(a,b,rez);
        a[0] = 5.5; a[1] = 12.4; b[0] = 1.0; b[1] = 3.0; rez[0] = 4.5; rez[1] = 9.4;
        passed = passed and subtract_test(a,b,rez);
        return passed;
    };
    bool subtract_test(double a[], double b[], double rez[]){
        ComplexNumber *n1 = new ComplexNumber(a[0],a[1]);
        ComplexNumber *n2 = new ComplexNumber(b[0],b[1]);
        ComplexNumber *ans = new ComplexNumber(0.0,0.2);
        *ans = *n1 - *n2;
        bool result = (ans->getReal() == rez[0]) and (ans->getIm() == rez[1]);
        delete(n1,n2,ans);
        return (result);
    };


    bool divide_tests(){
        bool passed = true;
        double a[2] = {0.0,0.0};
        double b[2] = {0.0,0.0};
        double rez[2] = {0.0,0.0};

        a[0] = 5.5; a[1] = 12.4; b[0] = 1.0; b[1] = 3.0; rez[0] = 4.27; rez[1] = -0.41;
        passed = passed and divide_test(a,b,rez);
        return passed;
    };

    bool divide_test(double a[], double b[], double rez[]){
        ComplexNumber *n1 = new ComplexNumber(a[0],a[1]);
        ComplexNumber *n2 = new ComplexNumber(b[0],b[1]);
        ComplexNumber *ans = new ComplexNumber(0.0,0.2);
        *ans = *n1 / *n2;
        //cout<<"devide:  "<<(double)ans.getReal() - (double)rez[0]<<"  expexted  "<<(double)rez[0]<<" "<<(double)rez[1]<<" i"<<endl;
        bool result = ((double)ans->getReal() - (double)rez[0] == 0.0) and ((double)ans->getIm() - (double)rez[1]) == 0;
        delete(n1, n2, ans);
        return (result);
    };

    bool multiply_tests(){
        bool passed = true;
        double a[2] = {0.0,0.0};
        double b[2] = {0.0,0.0};
        double rez[2] = {0.0,0.0};
        a[0] = 5.5; a[1] = 12.4; rez[0] = 0.0; rez[1] = 0.0;
        passed = passed and multiply_test(a,b,rez);
        a[0] = 5.5; a[1] = 12.4; b[0] = 1.0; b[1] = 3.0; rez[0] = -31.7; rez[1] = 28.9;
        passed = passed and multiply_test(a,b,rez);
        return passed;
    };

    bool multiply_test(double a[], double b[], double rez[]){
        ComplexNumber *n1 = new ComplexNumber(a[0],a[1]);
        ComplexNumber *n2 = new ComplexNumber(b[0],b[1]);
        ComplexNumber *ans = new ComplexNumber(0.0,0.0);
        *ans = *n1 * *n2;
        //cout<<"multiply:  "<<ans.toString()<<"  expexted  "<<rez[0]<<" "<<rez[1]<<" i"<<endl;
        bool result = (ans->getReal() == rez[0]) and (ans->getIm() == rez[1]);
        delete(n1, n2, ans);
        return (result);
    };

    bool complex_tests(){
        bool passed = true;
        double a[2] = {0.0,0.0};
        double b[2] = {0.0,0.0};
        double rez[2] = {0.0,0.0};
        a[0] = 5.5; a[1] = 12.4; rez[0] = 5.5; rez[1] = 12.4;
        passed = passed and complex_test(a,b,rez);
        a[0] = 5.5; a[1] = 12.4; b[0] = 1.0; b[1] = 3.0; rez[0] = 4.5; rez[1] = 9.4;
        passed = passed and complex_test(a,b,rez);
        return passed;
    };

    bool complex_test(double a[], double b[], double rez[]){
        ComplexNumber *n1 = new ComplexNumber(a[0],a[1]);
        ComplexNumber *n2 = new ComplexNumber(b[0],b[1]);
        ComplexNumber *ans = new ComplexNumber(0.0,0.2);
        *ans = n1 - n2;
        bool result = (ans->getReal() == rez[0]) and (ans->getIm() == rez[1]);
        delete(n1, n2, ans);
        return (result);
    };

};
