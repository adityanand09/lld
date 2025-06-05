#include "tic_tac_toe.h"
#include <set>

void TicTacToe::initializeGame() {
	// initialize board;
	m_board = new Board();
	// initialize players;
	int players_count;
	std::cout << "Enter number of players : ";
	std::cin >> players_count;
	std::set<char> used_piece_symbols;
	for (int i=0; i<players_count; i++) {
		Player *player = new Player();
		m_players.push_back(player);
	}
}

void TicTacToe::start() {
	std::string result = startGame();
	m_board->printBoard();
	std::cout << '\n' << result << '\n';
}

std::string TicTacToe::startGame() {
	bool no_winner = false;
	while (!no_winner) {
		if (m_board->getFreeCellsCount() == 0) {
			no_winner = true;
			continue;
		}

		Player *player = m_players.front();
		m_players.pop_front();

		int row, col;
		m_board->printBoard();

		while (true) {
			std::cout << player->getPlayerName() << ", Please choose a cell to fill (row, col) : ";
			std::cin >> row >> col;

			bool is_piece_added_successfully = m_board->addPiece(row, col, player->getPiece());
			if (!is_piece_added_successfully) {
				std::cout << "Choosen cell already filled, try another cell\n";
			} else {
				break;
			}
		}

		if (isThereWinner(player->getPiece())) {
			return "Winner is : " + player->getPlayerName();
		}

		m_players.push_back(player);
	}

	return "Game ended in TIE";
}

bool TicTacToe::isThereWinner(Piece* piece) {
	int board_size = m_board->getBoardSize();
	for (int row = 0; row < board_size; row++) {
		int col = board_size - 1;
		while (col >= 0) {
			if (m_board->getPiece(row, col) != piece) {
				break;
			}
			col--;
		}
		if (col < 0) return true;
	}
	for (int col = 0; col < board_size; col++) {
		int row = board_size - 1;
		while (row >= 0) {
			if (m_board->getPiece(row, col) != piece) {
				break;
			}
			row--;
		}
		if (row < 0) return true;
	}
	int diag = 0;
	for (diag = board_size - 1; diag >= 0; diag--) {
		if (m_board->getPiece(diag, diag) != piece) {
			break;
		}
	}
	if (diag < 0) return true;
	for (diag = board_size - 1; diag >= 0; diag--) {
		if (m_board->getPiece(diag, board_size - diag) != piece) {
			break;
		}
	}
	if (diag < 0) return true;
	return false;
}