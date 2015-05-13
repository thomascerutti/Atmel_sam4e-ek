/*
 * timer_sam4e.h
 *
 * Created: 02/04/2015 11:23:08
 *  Author: t.cerutti
 */ 


#ifndef TIMER_SAM4E_H_
#define TIMER_SAM4E_H_

#include "sam.h"

void timer_unlock_protection(Tc* Timer);

void timer_lock_protection(Tc* Timer);

void timer_enable_clock(Tc* Timer,unsigned char Channel);

void timer_disable_clock(Tc* Timer,unsigned char Channel);

void timer_clock_selection(Tc* Timer,unsigned char Channel,unsigned char Clock);

void timer_enable_capture_mode(Tc* Timer,unsigned char Channel);

void timer_enable_waveform_mode(Tc* Timer,unsigned char Channel);

void timer_up_counter(Tc* Timer,unsigned char Channel);

void timer_down_counter(Tc* Timer,unsigned char Channel);

void timer_reset_counter(Tc* Timer,unsigned char Channel);

int timer_get_counter_value(Tc* Timer,unsigned char Channel);


#endif /* TIMER_SAM4E_H_ */