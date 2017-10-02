#include "Switch.h"
#include <Arduino.h>

Switch::Switch()
{
	m_pin = 0;
	m_inverted = false;
	m_led_pin = 0;
}

Switch::Switch(int pin, bool inverted, int led_pin) 
{
	m_pin = pin;
	m_inverted = inverted;
	pinMode(m_pin, INPUT);
	Read();
	m_led_pin = led_pin;
	if (led_pin > -1)
	{
		pinMode(m_led_pin, OUTPUT);
		LEDOn();
	}
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
	if (m_led_pin > -1)
	{
		digitalWrite(m_led_pin, HIGH);
	}
}

void Switch::LEDOff()
{
	if (m_led_pin > -1)
	{
		digitalWrite(m_led_pin, LOW);
	}
}

void Switch::Read()
{
	m_last_state = digitalRead(m_pin);
	if (m_inverted)
		m_last_state = !m_last_state;
}