#include <bits/stdc++.h>

namespace {
    class Board{
        public:
            Board(int boardNumber);
            std::vector<int> tiles;
            std::vector<bool> tile_state;
            int boardNumber;
            void printBoard();
            bool isBoardWinner();
            bool hasCalledNumber(int calledNumber);
            int getAnswer(int calledNumber);
            void markOff(int calledNumber);
    };
    Board::Board(int boardNumber){
        for(int i = 0; i < 25; i++){
            tile_state.push_back(false);
        }
        this->boardNumber = boardNumber;
    }

    void Board::markOff(int calledNumber){
        int index = 0;
        for(int i = 0; i < tiles.size(); i++){
            if(tiles[i] == calledNumber)
                tile_state[i] = true;
        }
    }

    bool Board::hasCalledNumber(int calledNumber){
        for(auto&k : tiles){
            if(k == calledNumber)
                return true;
        }
        return false;
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
                    return ans;
                }
            }
        }
        for(int i = 0; i < 25; i+=5){
            if(tile_state[i]){
                if(tile_state[i+1] && tile_state[i+2] && tile_state[i+3] && tile_state[i+4]){
                    ans = true;
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
    infile.open("test.txt");
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
        Board board((i/5) + 1);
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
    std::ofstream outfile;
    outfile.open("output.txt");
    //For each instruction, check each board and mark off the corresponding index in tile_state that the calledNumber occurs in tile, if any
    for(int i = 0; i < instructions.size(); i++){
        //Get the "called" number
        outfile << "Step number " << i+1 << "\n";
        for(auto iter: finalBoards){
            outfile << "Board #: " << iter.boardNumber << "\n" << instructions[i] << "\n";
            for(int temp = 0; temp < iter.tiles.size(); temp++){
                if(temp%5==0)
                    outfile << "\n";
                outfile << iter.tiles[temp] << " ";
            }
            outfile << "\n";
        }
        outfile << "\n";
        int calledNumber = instructions[i];
        if(finalBoards.size() == 1){
            if(finalBoards[0].isBoardWinner()){
                std::cout << "This is board number: " << finalBoards[0].boardNumber << "\n";
                std::cout << finalBoards[0].getAnswer(calledNumber) << "\n";
                for(int temp = 0; temp < finalBoards[0].tile_state.size(); temp++){
                if(temp%5==0)
                    outfile << "\n";
                outfile << finalBoards[0].tiles[temp] << " ";
            }
                return 0;
            }
        }
        //for each board
        for(int j = 0; j < finalBoards.size(); j++){
           //check to see if current board has the called number.
           //If it does, mark off the corresponding tile_state index
           if(finalBoards[j].hasCalledNumber(calledNumber)){
               finalBoards[j].markOff(calledNumber);
           }
           //check if current board has won off the called number, if so, get answer
           if(finalBoards[j].isBoardWinner() && finalBoards.size() != 1){
               finalBoards.erase(finalBoards.begin()+j);
           }
        }
    }
    outfile.close();
    
    /*for(auto k: finalBoards){
        for(int i = 0; i < k.tiles.size(); i++){
            if(i%5==0)
                std::cout << "\n";
            std::cout << k.tiles[i] << " ";
        }
    }*/
    return 0;
}