#include "chessGame.h"

chessGame::chessGame(sf::Color bordCol1, sf::Color bordCol2)
: board(bordCol1, bordCol2), selected(false), playerTurn(true), mate(false), turn(1)
{
    font.openFromFile("Textures/arial.ttf");
    infoRestart.setFillColor(sf::Color::White);
    infoRestart.setOutlineThickness(-5.f);
    infoRestart.setOutlineColor(sf::Color::Black);
    infoRestart.setPosition(sf::Vector2f(512.f,0.f));
    infoRestart.setSize(sf::Vector2f(256.f,50.f));

    textRestart->setFont(font);
    textRestart->setString("RESTART");
    textRestart->setCharacterSize(24);
    textRestart->setStyle(sf::Text::Bold);
    textRestart->setFillColor(sf::Color::Black);
    textRestart->setPosition
    (
        sf::Vector2f
        (
            infoRestart.getPosition().x+75.f,
            infoRestart.getPosition().y+75.f
        )
    );

    textTurn->setFont(font);
    textTurn->setCharacterSize(24);
    textTurn->setStyle(sf::Text::Bold);
    textTurn->setFillColor(sf::Color::White);
    textTurn->setPosition(sf::Vector2f(530.f,70.f));

    textSituation->setFont(font);
    textSituation->setCharacterSize(24);
    textSituation->setStyle(sf::Text::Bold);
    textSituation->setFillColor(sf::Color::White);
    textSituation->setPosition(sf::Vector2f(530.f,110.f));

    textLastMove->setFont(font);
    textLastMove->setCharacterSize(24);
    textLastMove->setStyle(sf::Text::Bold);
    textLastMove->setFillColor(sf::Color::White);
    textLastMove->setPosition(sf::Vector2f(530.f,200.f));

    restart();
}

void chessGame:: restart()
{
    selected=false;
    playerTurn=true;
    playerTurnCheck=false;
    mate=false;
    turn=1;

    blackPieces[0].setPiece('R',false,7);//xe den ben trai
    blackPieces[1].setPiece('N',false,6);//ma den
    blackPieces[2].setPiece('B',false,5);//tuong den
    blackPieces[3].setPiece('K',false,4);//hau den
    blackPieces[4].setPiece('Q',false,3);//vua den
    blackPieces[5].setPiece('B',false,2);//tuong den
    blackPieces[6].setPiece('N',false,1);//ma den
    blackPieces[7].setPiece('R',false,0);//xe den ben phai

    whitePieces[0].setPiece('R',true,56);
    whitePieces[1].setPiece('N',true,57);
    whitePieces[2].setPiece('B',true,58);
    whitePieces[3].setPiece('K',true,59);
    whitePieces[4].setPiece('B',true,61);
    whitePieces[5].setPiece('N',true,62);
    whitePieces[6].setPiece('R',true,63);

    for(int i=8; i<16; i++)
    {
        whitePieces[i].setPiece('P',true,48+(i-8));
        blackPieces[i].setPiece('P',false, 15-(i-8));
    }
    calcPossibleMoves();
    textLastMove->setString(" ");
}

void chessGame:: updateInfo()
{
    textTurn->setString("Turn: "+ std::to_string(turn));
    textLastMove->setString(lastMove);
    if(!mate)
    {
        if(playerTurn)
        {
            textSituation->setString("White's Turn");
        }
        else 
            textSituation->setString("Black's Turn");
        if(playerTurnCheck)// neu ben nao dang bi chieu
        textSituation->setString(textSituation->getString()+ "\nCheck");
    }
    else
    {
        if(playerTurnCheck)
        {
            if(playerTurn)
            textSituation->setString("CHECKMATE\nBlack Wins");
            else
            textSituation->setString("CHECKMATE\nWhite Wins");
        }
        else textSituation->setString("STALEMATE\nIts a DRAW");
    }
}

void chessGame::draw(sf::RenderTarget&target, sf:: RenderStates states) const
{
    target.clear(sf::Color::Black);
    target.draw(board);
    target.draw(infoRestart);
    if(textRestart) target.draw(*textRestart);
    if(textTurn) target.draw(*textTurn);
    if(textSituation) target.draw(*textSituation);
    if(textLastMove) target.draw(*textLastMove);

    if(selectedPieces!=nullptr&& selected)
    {
        for(int i=0; i<possibleMovesSquares.size(); i++)
        {
            target.draw(possibleMovesSquares.at(i));
        }
    }
    for(int i=0; i<16; i++)
    {
        target.draw(whitePieces[i]);
        target.draw(blackPieces[i]);
    }
}

void chessGame:: createMoveSquares()
{
    if(selectedPieces==nullptr) return;
    possibleMovesSquares.clear();
    for(int i=0; i<selectedPieces->getPossibleMoves().size(); i++)
    {
        sf::RectangleShape tmp;
        tmp.setPosition(sf::Vector2f((selectedPieces->getPossibleMoves().at(i)%8)*64.f,(selectedPieces->getPossibleMoves().at(i)/8)*64.f));
        tmp.setSize(sf::Vector2f(64.f,64.f));
        tmp.setFillColor(sf::Color(0x66b4cc50));
        possibleMovesSquares.push_back(tmp);
    }
    sf::RectangleShape tmp;
    tmp.setPosition(sf::Vector2f((selectedPieces->getPosition()%8)*64.f,(selectedPieces->getPosition()/8)*64.f));
    tmp.setSize(sf::Vector2f(64.f,64.f));
    tmp.setFillColor(sf::Color(0x00000000));
    tmp.setOutlineColor(sf::Color::Red);
    tmp.setOutlineThickness(-3.f);
    possibleMovesSquares.push_back(tmp);
    return;
}

bool chessGame::selectPiece(int pos)
{
    selected=false;
    for(int i=0; i<16; i++)
    {
        if(playerTurn)
        {
            if(whitePieces[i].getPosition()==pos)
            {
                selectedPieces=&whitePieces[i];
                selected=true;
                break;
            }
        }
        else
        {
            if(blackPieces[i].getPosition()==pos)
            {
                selectedPieces=&blackPieces[i];
                selected=true;
                break;
            }
        }
    }
    if(!selected)
    {
        selectedPieces=nullptr;
        possibleMovesSquares.clear();
        return selected;
    }
    createMoveSquares();
    return selected;
}

// Xac dinh tat ca nuoc di hop le cua tung quan co tren ban co hien tai
// Chuan bi du lieu de nguoi choi click chon quan co thi game se hightlight cac o co the di
// Ho tro kiem tra cac trang thai dac biet nhu chieu, chieu het, het nuoc di.
void chessGame:: calcPossibleMoves()
{
    Piece*tmpPiece;// con tro tam de duyet tung quan co
    for(int x=0; x<32; x++)
    {
        if(x<16)
        {
            tmpPiece=&whitePieces[x];// tu 0 den 15 la quan trang
        }
        else tmpPiece=&blackPieces[x-16];
        tmpPiece->getPossibleMoves().clear();// xoa danh sach nuoc di/ o bi tan cong cu truoc khi tinh lai, de khong ton dong data
        tmpPiece->getDangerMoves().clear();
        if(tmpPiece->getPosition()==-1) continue;// neu vi tri=-1 nghia la quan co da bi an/khong con tren ban: bo qua
        switch (tmpPiece->getType())// goi ham tuong ung theo loai quan de tinh nuoc di va tinh o bi tan cong
        {
            case 'K':
            calcKingMoves(tmpPiece);
            break;
            case 'Q':
            calcQueenMoves(tmpPiece);
            break;
            case 'R':
            calcRookMoves(tmpPiece);
            break;
            case 'B':
            calcBishopMoves(tmpPiece);
            break;
            case 'N':
            calcKnightMoves(tmpPiece);
            break;
            case 'P':
            calcPawnMoves(tmpPiece);
            break;
        default:
            std:: cerr << "Error piece type does not exist.\n";
            break;
        }
    }
    for(int x=0; x<16; x++)// loc nhung nuoc di khong hop le cho ben dang di
    {
        if(playerTurn)
        {
            eraseMoves(&whitePieces[x]);
        }
        else eraseMoves(&blackPieces[x]);
    }
    checkMate();
    updateInfo();
    turn++;
}

// Ham dung de loc bo nhung nuoc di bat hop le: vi du nhung nuoc di cua minh lam vua cua minh bi chieu tuong
void chessGame:: eraseMoves(Piece* tmpPiece)
{
    if(tmpPiece->getPosition()==-1) return;// neu quan da bi an khong lam gi ca
    if(tmpPiece->getPlayer()==playerTurn)
    {
        for(int i=0; i<16; i++)
        {
            for(int j=0; j<tmpPiece->getPossibleMoves().size(); j++)
            {
                // loại bỏ các ô mà tmpPiece có thể đi nhưng đang bị đồng đội chiếm
                if(tmpPiece->getPlayer())// chi xu li quan cua ben dang di chuyen 
                {
                    if(tmpPiece->getPossibleMoves().at(j)==whitePieces[i].getPosition())
                    {
                        //xóa phần tử thứ j của vector posibleMove
                        tmpPiece->getPossibleMoves().erase(tmpPiece->getPossibleMoves().begin()+j);
                        break;// thoát inner-loop(qua i tiếp theo)
                    }
                }
                else
                {
                    if(tmpPiece->getPossibleMoves().at(j)==blackPieces[i].getPosition())
                    {
                        tmpPiece->getPossibleMoves().erase(tmpPiece->getPossibleMoves().begin()+j);
                        break;
                    }
                }
            }
        }
        if(tmpPiece->getType()=='K')
        {
            for(int j=0; j<tmpPiece->getPossibleMoves().size(); j++)
            {
                for(int i=0; i<16; i++)
                {
                    int o{0};
                    if(tmpPiece->getPlayer())
                    {
                        for(o=0; o<blackPieces[i].getPossibleMoves().size(); o++)
                        {
                            if(tmpPiece->getPossibleMoves().at(j)==blackPieces[i].getPossibleMoves().at(o))
                            {
                                tmpPiece->getPossibleMoves().erase(tmpPiece->getPossibleMoves().begin()+j--);
                                break;
                            }
                        }
                        if((o!=blackPieces[i].getPossibleMoves().size())) break;
                    }
                    else
                    {
                        for(o=0; o<whitePieces[i].getPossibleMoves().size(); o++)
                        {
                            if(tmpPiece->getPossibleMoves().at(j)==whitePieces[i].getPossibleMoves().at(o))
                            {
                                tmpPiece->getPossibleMoves().erase(tmpPiece->getPossibleMoves().begin()+j--);
                                break;
                            }
                        }
                        if( (o != whitePieces[i].getPossibleMoves().size()))
                            break;;
                    }
                }
            }
        }
        if(tmpPiece->getType()!='K')
        {
            for(int i=0; i<16; i++)
            {
                if(playerTurn&&(blackPieces[i].getDangerMoves().size()>1))
                {
                    for(int j=0; j< blackPieces[i].getDangerMoves().size(); j++)
                    {
                        if(blackPieces[i].getDangerMoves().at(j)==tmpPiece->getPosition())
                        {
                            std:: vector<int> tmpMove;
                            for(int x=0; x<tmpPiece->getPossibleMoves().size(); x++)
                            {
                                for(int k=0; k<blackPieces[i].getPossibleMoves().size(); k++)
                                {
                                    if(tmpPiece->getPossibleMoves().at(x)==blackPieces[i].getDangerMoves().at(k))
                                    {
                                        tmpMove.push_back(tmpPiece->getPossibleMoves().at(x));
                                    }
                                }
                            }
                            tmpPiece->getPossibleMoves().clear();
                            tmpPiece->getPossibleMoves()=tmpMove;
                            break;
                        }
                    }
                }
                else if(!playerTurn&&(whitePieces[i].getDangerMoves().size()>1))
                {
                    for(int j=0; j<whitePieces[i].getDangerMoves().size(); j++)
                    {
                         if(whitePieces[i].getDangerMoves().at(j) == tmpPiece->getPosition()){
                            std::vector<int> tmpMoves;
                            for(int x=0; x<tmpPiece->getPossibleMoves().size(); x++){
                                for(int k=0; k<whitePieces[i].getDangerMoves().size(); k++){
                                    if(tmpPiece->getPossibleMoves().at(x) == whitePieces[i].getDangerMoves().at(k))
                                        tmpMoves.push_back( tmpPiece->getPossibleMoves().at(x) );
                                }
                            }
                            tmpPiece->getPossibleMoves().clear();
                            tmpPiece->getPossibleMoves() = tmpMoves;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void chessGame:: calcKingMoves(Piece*tmpPiece)
{
    int piecePos= tmpPiece->getPosition();
    tmpPiece->getPossibleMoves().clear();
    if(piecePos/8!=0)
    {
        tmpPiece->getPossibleMoves().push_back(piecePos-8);
        if(piecePos%8!=0)
        {
            tmpPiece->getPossibleMoves().push_back(piecePos-8);
        }
        if(piecePos%8!=7)
        {
            tmpPiece->getPossibleMoves().push_back(piecePos-7);
        }
    }
    if(piecePos/8!=7)
    {
        tmpPiece->getPossibleMoves().push_back(piecePos+8);
        if(piecePos%8!=0)
        {
            tmpPiece->getPossibleMoves().push_back(piecePos+7);
        }
        if(piecePos%8!=7)
        {
            tmpPiece->getPossibleMoves().push_back(piecePos+9);
        }
    }
    if(piecePos%8!=0) tmpPiece->getPossibleMoves().push_back(piecePos-1);
    if(piecePos%8!=7) tmpPiece->getPossibleMoves().push_back(piecePos+1);
    //calcCastling(tmpPiece);
}
void chessGame:: calcQueenMoves(Piece*tmpPiece)
{
    int piecePos= tmpPiece->getPosition();
    int posCounter=1;
    bool dangerMove=false;
    bool finishLoop=false;
    tmpPiece->getPossibleMoves().clear();
    tmpPiece->getDangerMoves().clear();
    while((piecePos-posCounter>=0)&& ((piecePos/8)==(piecePos-posCounter)/8))// di chuyen trai
    {
        if(!finishLoop)
        {
            for(int i=0; i<16; i++)
            {
                if((whitePieces[i].getPosition()==(piecePos-posCounter))||(blackPieces[i].getPosition()==(piecePos-posCounter)))
                {
                    finishLoop=true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos-posCounter);
        }
        if(!dangerMove)
        {
            tmpPiece->getDangerMoves().push_back(piecePos-posCounter);
            if(!playerTurn)
            {
                if(piecePos-posCounter==blackPieces[3].getPosition()) dangerMove=true;
            }
            else
            {
                if(piecePos-posCounter==whitePieces[4].getPosition()) dangerMove=true;
            }
        }
    }
}
