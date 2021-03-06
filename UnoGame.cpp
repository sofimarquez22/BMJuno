//  created by Juhi Park.
//  copyright © 2018 Juhi Park. all rights reserved.

#include "UnoGame.hpp"

const Card UnoGame::deck_total[76] = {Card(0, "Red"), Card(1, "Red"), Card(2, "Red"),
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
    
    srand(static_cast<unsigned int>(time(NULL)));
}
void UnoGame::start(){
    //In the beginning of game
    //make sure each player don't own cards
    
    //make sure face up is empty
    assert(face_up.size() == 0);
    //put every cards to face down
    //shuffle the face down
    shuffle(face_down);
    
    //distribute 7 cards from face down to user
    int counter = 0;
    while(counter < 7){
        int i=face_down.size()-1;
        user.addCard(face_down[i]);
        face_down.pop_back();
        counter++;
    }
    
    //distribute 7 cards from face down to comp
    counter = 0;
    while(counter < 7){
        int i=face_down.size()-1;
        comp.addCard(face_down[i]);
        face_down.pop_back();
        counter++;
    }
    //get one card from face down to face up
    face_up.push_back(face_down[face_down.size()-1]);
    face_down.pop_back();
    
}
void UnoGame::play(){
    start();
  
    do{
        cout << "**\n**\nOn Deck\n";
        face_up[face_up.size()-1].displayCard();
        
        int deck_num = face_up[face_up.size()-1].getNum();
        string deck_color = face_up[face_up.size()-1].getColor();
        
        //starting with user turn
        cout << "YOUR TURN" << endl;
        user.seeMyCard();
        int user_turn;

        //inquiring user choice
        user_turn = getUserInput();

        if(user_turn == -1){
            //if has no match
            //check if facedown is empty
            check_facedown();
            //withdraw from facedown (face down not empty)
            user.addCard(face_down[face_down.size()-1]);
            face_down.pop_back();
            cout << "After Withdrawing" << endl;
            user.seeMyCard();
            //if that card can be played, play it
            user_turn = user.checkCard(deck_color, deck_num);
            
            if(user_turn != -1){
                add_to_faceup(user.putCard(user_turn));
            }
        }else{
            //found a card
            //put a card in the deck of faceup            
            add_to_faceup(user.putCard(user_turn));
        }
        
        
        //show the most recent card from face up
        cout << "**\n**\nOn Deck\n";
        face_up[face_up.size()-1].displayCard();
        
        //other wise, move on to the next comp player
        //comp turn
        cout << "COMPUTER TURN" << endl;
        
        deck_num = face_up[face_up.size()-1].getNum();
        deck_color = face_up[face_up.size()-1].getColor();
        int comp_turn = comp.checkCard(deck_color, deck_num);
        if(comp_turn == -1){
            check_facedown();
            comp.addCard(face_down[face_down.size()-1]);
            face_down.pop_back();
            //if that card can be played, play it
            comp_turn = comp.checkCard(deck_color, deck_num);
            if(comp_turn != -1){
                add_to_faceup(comp.putCard(comp_turn));
            }
        }else{
            //found a card
            //put a card in the deck of faceup
            add_to_faceup(comp.putCard(comp_turn));
        }
        
    }while(!end_game());
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
bool UnoGame::end_game(){
    //if either user has empty card
    if(user.emptyHand()){
        cout << "User won!" << endl;
        return true;
        //end game
        cout << "End of game" << endl;
    }
    //if comp has empty card
    if(comp.emptyHand()){
        cout << "Computer won!" << endl;
        return true;
        //end game
        cout << "End of game" << endl;
    }
    
    return false;
}
void UnoGame::add_to_faceup(Card c){
    //add to face up when player as a card that matches
    face_up.push_back(c);
    
}
void UnoGame::check_facedown(){
    //if face down are all gone
    if(face_down.empty()){
        
        //below is for resetting face_up
        //leave out the top car
        Card top = face_up.back();
        face_up.pop_back();
        
        //suffle everything else
        shuffle(face_up);
        
        //distribute it to face down
        while(!face_up.empty()){
            face_down.push_back(face_up.back());
            face_up.pop_back();
        }
        face_up.push_back(top);
        
    }//else there are still more card left in face down, don't do anything
}
int UnoGame::getUserInput(){
    int result;
    while(true){
            cout << "Choose card by index (Enter -1 to withdraw new card): ";
            cin >> result;

            //validating user's choice of card to see if that matches the 
            //face deck hasn't implemented yet
            
            //it only check whether user has entered -1 
            //or an index num within the size of user's hand
            if(result < user.getHandSize() && result >=-1){
                break;
            }
        }
    return result;
}

