#ifndef __PIECE_H__
#define __PIECE_H__
#include <set>
#include <iostream>

class Piece {

private:
	char m_piece_symbol;
	inline static std::set<char> m_used_symbols;
public:
	Piece();

	char getPieceSymbol();
};

#endif