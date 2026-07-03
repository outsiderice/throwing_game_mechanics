#include "Player.hpp"

Player::Player(void) : _body({(float)GetScreenWidth()/2-30, 300, 60, 80}), _isHolding(false)
{
	return ;
}

void	Player::setPosition(float direction)
{
	float	speed = 4.0f;
	_body.x += speed * direction;

	_body.x = Clamp(_body.x, 0, (float)GetScreenWidth() - _body.width);
	return ;
}


Rectangle	Player::getBody(void) const
{
	return (_body);
}

void	Player::downArrowAction(bool collision)
{
	if (_isHolding == true)
		putDown();
	else if (collision)
		pickUp();
	return ;
}

void	Player::putDown()
{
	_isHolding = false;
}

void	Player::pickUp()
{
	_isHolding = true;
}
