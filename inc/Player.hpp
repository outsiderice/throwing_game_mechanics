#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <raylibh.h>
#include <raymath.h>

class	Player{
	public:
		Player(void);

		//Setters
		void	setPosition(int key);

		//Getters
		bool		isHolding() const;
		Rectangle	getBody() const;

		void	downArrowAction();
		void	throwObject();

	private:
		Rectangle	_body;
		bool		_isHolding;

};

#endif
