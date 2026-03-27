#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <raylib.h>
#include <raymath.h>

class	Player{
	public:
		Player(void);

		//Setters
		void	setPosition(float direction);

		//Getters
		Rectangle	getBody(void) const;

//		void	downArrowAction();
//		void	putDown();
//		void	throwObject();

	private:
		Rectangle	_body;
		bool		_isHolding;

};

#endif
