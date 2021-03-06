#ifndef CARDS_H
#define CARDS_H

static const char SUITS[4][9]= {"♥","♠","♣","♦"};
static const char FACES[13][6]= {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
char * convertIntCardToString(int card);
struct Deck {
  int cards[52];
};
struct Hand {
  int * cards;
  int size;
};
struct Player {
  struct Hand hand;
  char name[140];
};
struct Game {
  struct Player players[2];
  struct Deck deck;
  struct Hand warHand;
  int numberOfPlayers;
};

int compareHands(int card1, int card2);
void playHand(struct Game* game);
void playWarHand(struct Game* game);
void initializeDeck(struct Deck* deck);
void captureTopCardFrom(struct Player* winner, struct Player* loser);
void sendTopCardToBottom(struct Player* player);
void addCardToHand(struct Player* player, int card);
int removeTopCardFromHand(struct Player* player);
void initializeHand(struct Hand* hand, int card);
void dealCards(struct Game *game);
struct Game* initializeGame();
void beginGame(struct Game* game);

#endif
