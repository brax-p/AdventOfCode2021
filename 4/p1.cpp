#include <bits/stdc++.h>

namespace {
    class Board{
        public:
            Board();
            std::vector<int> tiles;
            std::vector<bool> tile_state;
            void printBoard();
            bool isBoardWinner();
            int getAnswer(int calledNumber);
    };
    Board::Board(){
        for(int i = 0; i < 25; i++){
            tile_state.push_back(false);
        }
    }

    void Board::printBoard(){
        std::cout << tiles[0] << "\n";
    }

    bool Board::isBoardWinner() {
        bool ans = false;
        for(int i = 0; i < 5; i++){
            if(tile_state[i]){
                if(tile_state[i+5] && tile_state[i+10] && tile_state[i+15] && tile_state[i+20]){
                    ans = true;
                    std::cout << "first loop\n";
                    return ans;
                }
            }
        }
        for(int i = 0; i < 25; i+=5){
            if(tile_state[i]){
                if(tile_state[i+1] && tile_state[i+2] && tile_state[i+3] && tile_state[i+4]){
                    ans = true;
                    std::cout << "second loop\n";
                    return ans;
                }
            }
        }
        return ans;
    }

    int Board::getAnswer(int calledNumber){
        int sum = 0;
        for(int i = 0; i < tile_state.size(); i++){
            if(tile_state[i] == false){
                sum+=tiles[i];
            }
        }
        std::cout << sum << " is the sum\n";
        sum = sum * calledNumber;
        std::cout << calledNumber << " is the called Number\n";
        return sum;
    }
}

void printVec(std::vector<int> vec){
    for(auto k: vec)
        std::cout << k << ' ';
    std::cout << "\n";
}

std::vector<int> setInstructions(std::string line){
    std::vector<int> instructions = {};
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;

    while((pos = line.find(delimiter)) != std::string::npos){
        token = line.substr(0,pos);
        instructions.push_back(stoi(token));
        line.erase(0,pos+delimiter.length());
    }
    instructions.push_back(stoi(line));
    return instructions;
}

int main()
{
    std::ifstream infile;
    infile.open("input.txt");
    int lineCount = 0;
    std::string line;
    std::vector<int> instructions = {};
    std::vector<std::vector<int>> boards = {};
    std::vector<Board> finalBoards = {};
    while(infile.is_open()){
        while(getline(infile, line)){
            if(lineCount == 0){
                instructions = setInstructions(line);
            }
            else if(lineCount > 0){
                int num;
                std::vector<int> localLine = {};
                for(int i = 0; i < 5; i++){
                    infile >> num;
                    localLine.push_back(num);
                }
                boards.push_back(localLine);
            }
            lineCount++;
        }
        infile.close();
    }
    for(int i = 0; i < boards.size(); i+=5){
        Board board;
        std::vector<int> tempTiles = {};
        for(int k = 0; k < 5; k++){
            std::vector<int> currentTemp = boards[i+k];
            for(auto k: currentTemp){
                tempTiles.push_back(k);
            }
        }
        board.tiles = tempTiles;
        finalBoards.push_back(board);
    }
    //Game loop
    for(int i = 0; i < instructions.size(); i++){
        int calledNumber = instructions[i];
        for(int t = 0; t < finalBoards.size(); t++){
            int indexOnBoard = 0;
            for(int j = 0; j < finalBoards[t].tiles.size(); j++){
                if(finalBoards[t].tiles[j] == calledNumber){
                    indexOnBoard = j;
                }
            }
            finalBoards[t].tile_state[indexOnBoard] = true;
            if(finalBoards[t].isBoardWinner()){
                int answer = finalBoards[t].getAnswer(calledNumber);
                for(int num = 0; num < finalBoards[t].tile_state.size(); num++){
                    if(num%5 == 0)
                        std::cout << "\n";
                    std::cout << finalBoards[t].tile_state[num] << " ";
                }
                for(int temp = 0; temp < finalBoards[t].tiles.size(); temp++){
                    if(temp%5==0)
                        std::cout << "\n";
                    std::cout << finalBoards[t].tiles[temp] << " ";
                }
                std::cout << "\nThis is the answer: " << answer << std::endl;
                return 0;
            }
        }
    }
    for(int i = 0; i < finalBoards.size(); i++){
        Board tempBoard = finalBoards[i];
        for(auto k: tempBoard.tile_state){
            std::cout << k << " ";
        }
        std::cout << "\n";
    }
    return 0;
}