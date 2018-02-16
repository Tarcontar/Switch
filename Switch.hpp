#pragma once

class Switch
{
	public:
		Switch();
		Switch(int pin, bool inverted = false, int led_pin = -1);
		
		bool On();
		bool Off();
		bool SwitchedOn();
		bool SwitchedOff();

		void LEDOn();
		void LEDOff();
		
		//-1 not a analog pin
		// 0  not connected
		// 1 connected
		int connected();
		
	private:
		int		m_pin;
		int		m_led_pin;
		bool	m_last_state;
		bool 	m_inverted;
		
	private:
		void Read();
};
