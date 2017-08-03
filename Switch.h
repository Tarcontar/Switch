#pragma once

class Switch
{
	public:
		Switch(int pin, bool inverted = false);
		Switch(int pin, int led_pin, bool inverted = false);
		
		bool On();
		bool Off();
		bool SwitchedOn();
		bool SwitchedOff();

		void LEDOn();
		void LEDOff();

	private:
		int		m_pin;
		int		m_led_pin;
		bool	m_last_state;
		bool 	m_inverted;
		
	private:
		void Read();
};
