#pragma once
#include <string>


enum class Color
{
	Hearts,
	Spades,
	Diamonds,
	Clubs,

	Size
};

enum class Value
{
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace,

	Size
};

struct Card
{
	Color color;
	Value value;

	std::string toString() const {
		std::string colorStr;
		switch (color) {
		case Color::Hearts: colorStr = "Hearts"; break;
		case Color::Spades: colorStr = "Spades"; break;
		case Color::Diamonds: colorStr = "Diamonds"; break;
		case Color::Clubs: colorStr = "Clubs"; break;
		default: colorStr = "Unknown"; break;
		}
		std::string valueStr;
		switch (value) {
		case Value::Two: valueStr = "Two"; break;
		case Value::Three: valueStr = "Three"; break;
		case Value::Four: valueStr = "Four"; break;
		case Value::Five: valueStr = "Five"; break;
		case Value::Six: valueStr = "Six"; break;
		case Value::Seven: valueStr = "Seven"; break;
		case Value::Eight: valueStr = "Eight"; break;
		case Value::Nine: valueStr = "Nine"; break;
		case Value::Ten: valueStr = "Ten"; break;
		case Value::Jack: valueStr = "Jack"; break;
		case Value::Queen: valueStr = "Queen"; break;
		case Value::King: valueStr = "King"; break;
		case Value::Ace: valueStr = "Ace"; break;
		default: valueStr = "Unknown"; break;
		}
		return "Card: " + valueStr + " of " + colorStr;
	}
};