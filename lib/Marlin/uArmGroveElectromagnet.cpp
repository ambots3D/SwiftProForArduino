/**
 * uArm Swift Pro Firmware
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "uArmGroveElectromagnet.h"


uArmGroveElectromagnet::uArmGroveElectromagnet()
{

}

bool uArmGroveElectromagnet::init(uint8_t portNum, uint8_t clk_pin, uint8_t dat_pin)
{
	_portNum = portNum;
	_clk_pin = clk_pin;
	_dat_pin = dat_pin;	

	_groveelectromagnet.setPin(_clk_pin);
	
	return true;
}

void uArmGroveElectromagnet::report()
{

}

void uArmGroveElectromagnet::control()
{
	uint8_t value;		
	
	if (code_seen('V'))
	{
		value = code_value_byte();	

		if (value)
		{
			_groveelectromagnet.on();
		}
		else
		{
			_groveelectromagnet.off();
		}
	}		
}

void uArmGroveElectromagnet::tick()
{
}

