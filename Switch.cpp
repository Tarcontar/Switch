#include "Switch.h"
#include <Arduino.h>

Switch::Switch(int pin, bool inverted) : m_pin(pin), m_inverted(inverted)
{
	pinMode(m_pin, INPUT);
	Read();
}

Switch::Switch(int pin, int led_pin, bool inverted) : Switch(pin, inverted)
{
	m_led_pin = led_pin;
	pinMode(m_led_pin, OUTPUT);
	LEDOn();
}

bool Switch::On()
{
	Read();
	return m_last_state == HIGH;
}

bool Switch::Off()
{
	Read();
	return m_last_state == LOW;
}

bool Switch::SwitchedOn()
{
	if (m_last_state == HIGH)
	{
		Read();
		return false;
	}
	Read();
	if (m_last_state == HIGH)
	{
		return true;
	}
	return false;
}

bool Switch::SwitchedOff()
{
	if (m_last_state == LOW)
	{
		Read();
		return false;
	}
	Read();
	if (m_last_state == LOW)
	{
		return true;
	}
	return false;
}

void Switch::LEDOn()
{
	digitalWrite(m_led_pin, HIGH);
}

void Switch::LEDOff()
{
	digitalWrite(m_led_pin, LOW);
}

void Switch::Read()
{
	//TODO: use m_inverted here
	m_last_state = digitalRead(m_pin);
}