/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/* figures:
6 - paw, 
5 - knight, 
4 - bishop, 
3 - rook,
2 - visir,
1 - king,
0 - empty.
*/
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> coordinate;
//enum Chess_Figures {pawn, knight, bishop, rook, queen, king}
int get_proection(char c){
    if(c >= 'a' && c <= 'h'){
        return c - 'a';
    }
    else if(c >= '1' && c <='8'){
        return c - '1';
    }
    else switch (c){//50 - pawn
        case 'K':{return 10; break;}// - king
        case 'B':{return 20; break;}// - bishop
        case 'R':{return 30; break;}// - rook
        case 'Q':{return 40; break;}// - queen
        case '-':{return 70; break;}// - step
        case ':':{return 71; break;}// - del
        case 'n':{return 50; break;}// - knight
        default :{return -1;}
    }
}
//enum Color {black, white};
struct Figure{
    int index = -1;
    int side = -1;
};
struct Step_type{
    int index = 60;
    int type_index = 70;
    coordinate to = coordinate(-1, -1), from = coordinate(-1, -1);
};
Step_type retranslate(string Hod){
    Step_type form;
    vector<int> codes(Hod.size(), -1);
    for(int i = 0; i < Hod.size(); i++){
        codes[i] = get_proection(Hod[i]);
    }
    for(int i = codes[codes.size() - 1]; i > -1; i--){
        if(codes[i] <= 8 && codes[i] >= 1){
            if(form.to.first == -1){
                form.to.second = codes[i];
                form.to.first = codes[i - 1];
                i--;
            }
            else if(i > 0 && codes[i - 1] <= 8 && codes[i - 1] >= 1){
                form.from.first = codes[i - 1];
                form.from.second = codes[i];
                i--;
            }
            else{
                form.from.first = codes[i];
            }
        }
        else if(codes[i] == 71){
            form.type_index = codes[i];
        }
        else if(codes[i] >= 10 && codes[i] <= 50 && form.index == 1){
            form.index = codes[i];
        }
    }
    return form;
}
typedef vector<vector<Figure> > table;
class Chess{
    table chess_desk;
public:
    Chess(int horizontal_number = 8, int vertical_number = 8):chess_desk(horizontal_number, 
     vector<Figure>(vertical_number)){
        //start_position();
    }
    Figure get_who_in_cell(coordinate a){
        return chess_desk[a.first][a.second];
    }
    void Get_Step(Step_type fot){
        
    }
//private:
    void input_Figure(Figure f, coordinate a){
        chess_desk[a.first][a.second] = f;
    }
};
int main()
{
    Chess desk;
    Figure our;
    our.index = 60;
        our.side = 0;
        for(int i = 0; i < 8; i++){
            desk.input_Figure(our, coordinate(1,i));
        }
        our.side = 1;
        for(int i = 0; i < 8; i++){
            desk.input_Figure(our, coordinate(6,i));
        }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            our = desk.get_who_in_cell(coordinate(i,j));
            switch (our.index)  {
                case 10:{cout << "K" << our.side; break;}
                case 20:{cout << "B" << our.side; break;}
                case 30:{cout << "R" << our.side; break;}
                case 40:{cout << "Q" << our.side; break;}
                case 50:{cout << "Kn" << our.side; break;}
                case 60:{cout << "P" << our.side; break;}
                default :{cout << "-";}}
            cout << " ";
        }
        cout << endl;
    }
}