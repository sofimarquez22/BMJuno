#ifndef UNOGAME_HPP
#define UNOGAME_HPP

class UnoGame{
protected:
    static const Card deck_total[76];
    Player user;
    Player comp;
    vector<Card> face_up;
    vector<Card> face_down;
    

public:
    UnoGame();
    void start();
    void play();
    void shuffle();
    void end_game();
    void add_to_faceup(Card c);
    void check_facedown();
    
};

#endif //UNOGAME_HPP 
