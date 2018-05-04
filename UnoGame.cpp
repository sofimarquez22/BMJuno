//  created by Juhi Park.
//  copyright © 2018 Juhi Park. all rights reserved.

#include "UnoGame.hpp"

Card UnoGame::deck_total[76] = {Card(0, "Red"), Card(1, "Red"), Card(2, "Red"),
    Card(3, "Red"), Card(4, "Red"), Card(5, "Red"), Card(6, "Red"),
    Card(7, "Red"), Card(8, "Red"), Card(9, "Red"), Card(1, "Red"),
    Card(2, "Red"), Card(3, "Red"), Card(4, "Red"), Card(5, "Red"),
    Card(6, "Red"), Card(7, "Red"), Card(8, "Red"), Card(9, "Red"),
    Card(0, "Yellow"), Card(1, "Yellow"), Card(2, "Yellow"),
    Card(3, "Yellow"), Card(4, "Yellow"), Card(5, "Yellow"), Card(6, "Yellow"),
    Card(7, "Yellow"), Card(8, "Yellow"), Card(9, "Yellow"), Card(1, "Yellow"),
    Card(2, "Yellow"), Card(3, "Yellow"), Card(4, "Yellow"), Card(5, "Yellow"),
    Card(6, "Yellow"), Card(7, "Yellow"), Card(8, "Yellow"), Card(9, "Yellow"),
    Card(0, "Green"), Card(1, "Green"), Card(2, "Green"),
    Card(3, "Green"), Card(4, "Green"), Card(5, "Green"), Card(6, "Green"),
    Card(7, "Green"), Card(8, "Green"), Card(9, "Green"), Card(1, "Green"),
    Card(2, "Green"), Card(3, "Green"), Card(4, "Green"), Card(5, "Green"),
    Card(6, "Green"), Card(7, "Green"), Card(8, "Green"), Card(9, "Green"),
    Card(0, "Blue"), Card(1, "Blue"), Card(2, "Blue"),
    Card(3, "Blue"), Card(4, "Blue"), Card(5, "Blue"), Card(6, "Blue"),
    Card(7, "Blue"), Card(8, "Blue"), Card(9, "Blue"), Card(1, "Blue"),
    Card(2, "Blue"), Card(3, "Blue"), Card(4, "Blue"), Card(5, "Blue"),
    Card(6, "Blue"), Card(7, "Blue"), Card(8, "Blue"), Card(9, "Blue")
};
UnoGame::UnoGame(){

    //Card deck_total[76];
    user = Player();
    comp = Player();

    //leave face_up empty 

    //put every cards to face down
    for(int i=0; i<76; i++)
        face_down.push_back(deck_total[i]);

}
void UnoGame::start(){
    //In the beginning of game
    //make sure each player don't own cards
    //make sure face up is empty
    //put every cards to face down
    //shuffle the face down
    shuffle(face_down);

    //distribute 7 cards from face down to user
    for(int i=0; i<7; i++){
        user.addCard(face_down[i]);
    }
    //distribute 7 cards from face down to comp
    //get one card from face down to face up
    

}
void UnoGame::play(){
    
}
void UnoGame::shuffle(vector<Card>& cards){
    unsigned int r_index = 0, total_num = cards.size();
    for(int i=0; i<total_num-1; i++){
        r_index = rand() % total_num; // generate index num between 0 and total_num-1
        assert(r_index >= 0 && r_index < total_num);
        Card temp = cards[i];
        cards[i] = cards[r_index];
        cards[r_index] = temp;
    }

}
void UnoGame::end_game(){
    //if

}
void UnoGame::add_to_faceup(Card c){
    //add to face up when player as a card that matches 
    //putCard(num, color);

    face_up.push_back(c);
    //show the most recent card from face up
}
void UnoGame::check_facedown(){
    //if face down are all gone
    if(face_down.empty()){
        //reset_face up
        
        //leave out the top car
        Card top = *face_up.end();
        face_up.pop_back();
     
        //suffle everything else
        shuffle(face_up);
        
        //distribute it to face down
        for(int i=face_up.size()-1; i>=0; i--){
            face_down.push_back(face_up[i]);
            face_up.pop_back();
        }

    }//else there are still more card left in face down, don't do anything
}
