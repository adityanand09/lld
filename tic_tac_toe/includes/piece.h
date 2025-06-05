#ifndef __PIECE_H__
#define __PIECE_H__

class Piece {

private:
	char m_piece_symbol;

public:
	Piece(char piece_symbol);

	char getPieceSymbol();
};

#endif