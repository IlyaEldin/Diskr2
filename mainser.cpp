#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
bool ai(bool a, bool b)
{
    return (!(!a || b));
}//антиимпликация
bool i(bool a, bool b)
{
    return (!a || b);
}//импликация
bool eq(bool a, bool b)
{
    return (!(a^b));
}//эквивалентность
bool f2(bool x,bool y)
{
    bool l=!(!x&&!y);//вводимаая функция
    return l;
}
bool f1(bool x,bool y)
{
    bool l=eq(x,y);//вводимаая функция
    return l;
}
bool polzhev1(bool & samka1)
{
    bool Lin=1;
    cout<<"ПОЛИНОМ ЖЕГАЛКИНА 1 функции: "<<endl;
    string G="(";
    bool zna[4],znach[4],znach1[4];
    bool x,y;
    int d=4;
    for (int i=0; i<d; i++) {{
            if (i<(d/2)) {
                x=0;
            } else {
                x=1;
            }
            if ((i%2)==1) {
                y=1;
            } else {
                y=0;
            }

        }

        znach[i]=f1(x,y);
        cout<<znach[i];
    }

    for(int i=0; i<d/2; i++) {
        if ((!znach[i])!=znach[3-i]) {

            samka1=0;
        }
    }

    cout<<endl;
    zna[3]=znach[0];
    int k=3;
    while (k>0) {
        for(int i=0; i<k; i++) {
            znach1[i]=znach[i]^znach[i+1];
            cout<<znach1[i];
            zna[k-1]=znach1[0];
        }
        cout<<endl;
        for(int i=0; i<k; i++) {
            znach[i]=znach1[i];
        }
        k--;
    }
    reverse(zna,zna+4);
    for(int i=0; i<4; i++) {
        if (zna[i]==1) {
            switch (i) {
            case 0:
                G=G+"1)+(";
                break;
            case 1:
                G=G+"y"+")+(";
                break;
            case 2:
                G=G+"x"+")+(";
                break;
            case 3:
                G=G+"xy"+")+(";
                Lin=0;
                break;
            }
        }
    }
    G=G.substr (0,G.length()-2);
    cout<<G<<endl;
    return Lin;
}
bool polzhev2(bool & samka2)
{
    bool Lin=1;
    cout<<"ПОЛИНОМ ЖЕГАЛКИНА 2 функции: "<<endl;
    string G="(";
    bool zna[4],znach[4],znach1[4];
    bool x,y;
    int d=4;
    for (int i=0; i<d; i++) {{
            if (i<(d/2)) {
                x=0;
            } else {
                x=1;
            }
            if ((i%2)==1) {
                y=1;
            } else {
                y=0;
            }
        }
        znach[i]=f2(x,y);
        cout<<znach[i];
    }
    for(int i=0; i<d/2; i++) {
        if ((!znach[i])!=znach[3-i]) {
            samka2=0;
        }
    }
    cout<<endl;
    zna[3]=znach[0];
    int k=3;
    while (k>0) {
        for(int i=0; i<k; i++) {
            znach1[i]=znach[i]^znach[i+1];
            cout<<znach1[i];
            zna[k-1]=znach1[0];
        }
        cout<<endl;
        for(int i=0; i<k; i++) {
            znach[i]=znach1[i];
        }
        k--;
    }
    reverse(zna,zna+4);
    for(int i=0; i<4; i++) {
        if (zna[i]==1) {
            switch (i) {
            case 0:
                G=G+"1)+(";
                break;
            case 1:
                G=G+"y"+")+(";
                break;
            case 2:
                G=G+"x"+")+(";
                break;
            case 3:
                G=G+"xy"+")+(";
                Lin=0;
                break;
            }
        }
    }
    G=G.substr (0,G.length()-2);
    cout<<G<<endl;
    return Lin;
}
bool xyz (bool & M, bool & Mn, bool & T10, bool & T20,bool & T11,bool & T21)
{
    cout<<"Таблица истинности: "<<endl;
    cout<<setw(5)<<"x";
    cout<<setw(5)<<"y";
    cout<<setw(5)<<"f1";
    cout<<setw(5)<<"f2"<<endl;
    bool x,y;
    int d=4;
    bool fon[4]= {0};
    bool ftw[4]= {0};
    for (int i=0; i<d; i++) {{
            if (i<(d/2)) {
                x=0;
            } else {
                x=1;
            }
            if ((i%2)==1) {
                y=1;
            } else {
                y=0;
            }
        }
        if (((x==0)&&(y==0))&&(f1(x,y)==0)) {
            T10=1;
        }
        if (((x==0)&&(y==0))&&(f2(x,y)==0)) {
            T20=1;
        }
        if (((x==1)&&(y==1))&&(f1(x,y)==1)) {
            T11=1;
        }
        if (((x==1)&&(y==1))&&(f2(x,y)==1)) {
            T21=1;
        }
        fon[i]=f1(x,y);
        ftw[i]=f2(x,y);
        cout<<setw(5)<<x;
        cout<<setw(5)<<y;
        cout<<setw(5)<<f1(x,y);
        cout<<setw(5)<<f2(x,y)<<endl;

    }
    for(int i=0; i<3; i++) {
        if (fon[i+1]<fon[i]) {
            M=0;
            break;
        }
    }
    for(int i=0; i<3; i++) {
        if (ftw[i+1]<ftw[i]) {
            Mn=0;
            break;
        }
    }
}
int main()
{
    bool T10=0,T20=0,T11=0,T21=0;
    bool M1=1;
    bool M2=1;
    bool s1=1;
    bool s2=1;
    xyz(M1,M2,T10,T20,T11,T21);
    bool Lin1=polzhev1(s1);
    bool Lin2=polzhev2(s2);
    cout<<"line "<<Lin1<<Lin2<<endl;
    cout<<"Mono "<<M1<<M2<<endl;
    cout<<"samov "<<s1<<s2<<endl;
    cout<<"sT0 "<<T10<<T20<<endl;
    cout<<"sT1 "<<T11<<T21<<endl;
    return 0;
}
// & & — логическое «И» или логическое умножение (конъюнкция). Оператор И возвращает истину, если верны оба утверждения.
// || — логическое «ИЛИ» или логическое сложение (дизъюнкция). Оператор ИЛИ возвращает истину, если верно хотя бы одно утверждение.
// ! — логическое отрицание. Возвращает истину, если утверждение ложно.
// ^ + по модулю 2
// !(&&) - антиконьюнкция
// ! (||) -антидизъюнкция
