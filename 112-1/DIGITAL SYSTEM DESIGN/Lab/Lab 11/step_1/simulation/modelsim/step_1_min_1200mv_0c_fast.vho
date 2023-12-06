-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.1.0 Build 162 10/23/2013 SJ Web Edition"

-- DATE "12/06/2023 11:44:55"

-- 
-- Device: Altera EP3C16F484C6 Package FBGA484
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY CYCLONEIII;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIII.CYCLONEIII_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	step_1 IS
    PORT (
	clk : IN std_logic;
	reset : IN std_logic;
	led : BUFFER std_logic_vector(7 DOWNTO 0)
	);
END step_1;

-- Design Ports Information
-- led[0]	=>  Location: PIN_J1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- led[1]	=>  Location: PIN_J2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- led[2]	=>  Location: PIN_J3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- led[3]	=>  Location: PIN_H1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- led[4]	=>  Location: PIN_F2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- led[5]	=>  Location: PIN_E1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- led[6]	=>  Location: PIN_C1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- led[7]	=>  Location: PIN_C2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clk	=>  Location: PIN_G3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reset	=>  Location: PIN_H2,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF step_1 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_clk : std_logic;
SIGNAL ww_reset : std_logic;
SIGNAL ww_led : std_logic_vector(7 DOWNTO 0);
SIGNAL \led[0]~output_o\ : std_logic;
SIGNAL \led[1]~output_o\ : std_logic;
SIGNAL \led[2]~output_o\ : std_logic;
SIGNAL \led[3]~output_o\ : std_logic;
SIGNAL \led[4]~output_o\ : std_logic;
SIGNAL \led[5]~output_o\ : std_logic;
SIGNAL \led[6]~output_o\ : std_logic;
SIGNAL \led[7]~output_o\ : std_logic;
SIGNAL \clk~input_o\ : std_logic;
SIGNAL \led[7]~1_combout\ : std_logic;
SIGNAL \reset~input_o\ : std_logic;
SIGNAL \led[7]~reg0_q\ : std_logic;
SIGNAL \led[6]~0_combout\ : std_logic;
SIGNAL \led[6]~reg0_q\ : std_logic;
SIGNAL \led[5]~reg0feeder_combout\ : std_logic;
SIGNAL \led[5]~reg0_q\ : std_logic;
SIGNAL \led[4]~reg0feeder_combout\ : std_logic;
SIGNAL \led[4]~reg0_q\ : std_logic;
SIGNAL \led[3]~reg0feeder_combout\ : std_logic;
SIGNAL \led[3]~reg0_q\ : std_logic;
SIGNAL \led[2]~reg0feeder_combout\ : std_logic;
SIGNAL \led[2]~reg0_q\ : std_logic;
SIGNAL \led[1]~reg0feeder_combout\ : std_logic;
SIGNAL \led[1]~reg0_q\ : std_logic;
SIGNAL \led[0]~reg0feeder_combout\ : std_logic;
SIGNAL \led[0]~reg0_q\ : std_logic;
SIGNAL \ALT_INV_led[7]~reg0_q\ : std_logic;

BEGIN

ww_clk <= clk;
ww_reset <= reset;
led <= ww_led;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_led[7]~reg0_q\ <= NOT \led[7]~reg0_q\;

-- Location: IOOBUF_X0_Y20_N9
\led[0]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \led[0]~reg0_q\,
	devoe => ww_devoe,
	o => \led[0]~output_o\);

-- Location: IOOBUF_X0_Y20_N2
\led[1]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \led[1]~reg0_q\,
	devoe => ww_devoe,
	o => \led[1]~output_o\);

-- Location: IOOBUF_X0_Y21_N23
\led[2]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \led[2]~reg0_q\,
	devoe => ww_devoe,
	o => \led[2]~output_o\);

-- Location: IOOBUF_X0_Y21_N16
\led[3]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \led[3]~reg0_q\,
	devoe => ww_devoe,
	o => \led[3]~output_o\);

-- Location: IOOBUF_X0_Y24_N23
\led[4]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \led[4]~reg0_q\,
	devoe => ww_devoe,
	o => \led[4]~output_o\);

-- Location: IOOBUF_X0_Y24_N16
\led[5]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \led[5]~reg0_q\,
	devoe => ww_devoe,
	o => \led[5]~output_o\);

-- Location: IOOBUF_X0_Y26_N23
\led[6]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \led[6]~reg0_q\,
	devoe => ww_devoe,
	o => \led[6]~output_o\);

-- Location: IOOBUF_X0_Y26_N16
\led[7]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_led[7]~reg0_q\,
	devoe => ww_devoe,
	o => \led[7]~output_o\);

-- Location: IOIBUF_X0_Y23_N15
\clk~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clk,
	o => \clk~input_o\);

-- Location: LCCOMB_X1_Y23_N18
\led[7]~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \led[7]~1_combout\ = !\led[0]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \led[0]~reg0_q\,
	combout => \led[7]~1_combout\);

-- Location: IOIBUF_X0_Y21_N8
\reset~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reset,
	o => \reset~input_o\);

-- Location: FF_X1_Y23_N19
\led[7]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~input_o\,
	d => \led[7]~1_combout\,
	clrn => \reset~input_o\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \led[7]~reg0_q\);

-- Location: LCCOMB_X1_Y23_N20
\led[6]~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \led[6]~0_combout\ = !\led[7]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \led[7]~reg0_q\,
	combout => \led[6]~0_combout\);

-- Location: FF_X1_Y23_N21
\led[6]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~input_o\,
	d => \led[6]~0_combout\,
	clrn => \reset~input_o\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \led[6]~reg0_q\);

-- Location: LCCOMB_X1_Y23_N6
\led[5]~reg0feeder\ : cycloneiii_lcell_comb
-- Equation(s):
-- \led[5]~reg0feeder_combout\ = \led[6]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \led[6]~reg0_q\,
	combout => \led[5]~reg0feeder_combout\);

-- Location: FF_X1_Y23_N7
\led[5]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~input_o\,
	d => \led[5]~reg0feeder_combout\,
	clrn => \reset~input_o\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \led[5]~reg0_q\);

-- Location: LCCOMB_X1_Y23_N0
\led[4]~reg0feeder\ : cycloneiii_lcell_comb
-- Equation(s):
-- \led[4]~reg0feeder_combout\ = \led[5]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \led[5]~reg0_q\,
	combout => \led[4]~reg0feeder_combout\);

-- Location: FF_X1_Y23_N1
\led[4]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~input_o\,
	d => \led[4]~reg0feeder_combout\,
	clrn => \reset~input_o\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \led[4]~reg0_q\);

-- Location: LCCOMB_X1_Y23_N2
\led[3]~reg0feeder\ : cycloneiii_lcell_comb
-- Equation(s):
-- \led[3]~reg0feeder_combout\ = \led[4]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \led[4]~reg0_q\,
	combout => \led[3]~reg0feeder_combout\);

-- Location: FF_X1_Y23_N3
\led[3]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~input_o\,
	d => \led[3]~reg0feeder_combout\,
	clrn => \reset~input_o\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \led[3]~reg0_q\);

-- Location: LCCOMB_X1_Y23_N12
\led[2]~reg0feeder\ : cycloneiii_lcell_comb
-- Equation(s):
-- \led[2]~reg0feeder_combout\ = \led[3]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \led[3]~reg0_q\,
	combout => \led[2]~reg0feeder_combout\);

-- Location: FF_X1_Y23_N13
\led[2]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~input_o\,
	d => \led[2]~reg0feeder_combout\,
	clrn => \reset~input_o\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \led[2]~reg0_q\);

-- Location: LCCOMB_X1_Y23_N10
\led[1]~reg0feeder\ : cycloneiii_lcell_comb
-- Equation(s):
-- \led[1]~reg0feeder_combout\ = \led[2]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \led[2]~reg0_q\,
	combout => \led[1]~reg0feeder_combout\);

-- Location: FF_X1_Y23_N11
\led[1]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~input_o\,
	d => \led[1]~reg0feeder_combout\,
	clrn => \reset~input_o\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \led[1]~reg0_q\);

-- Location: LCCOMB_X1_Y23_N28
\led[0]~reg0feeder\ : cycloneiii_lcell_comb
-- Equation(s):
-- \led[0]~reg0feeder_combout\ = \led[1]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \led[1]~reg0_q\,
	combout => \led[0]~reg0feeder_combout\);

-- Location: FF_X1_Y23_N29
\led[0]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~input_o\,
	d => \led[0]~reg0feeder_combout\,
	clrn => \reset~input_o\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \led[0]~reg0_q\);

ww_led(0) <= \led[0]~output_o\;

ww_led(1) <= \led[1]~output_o\;

ww_led(2) <= \led[2]~output_o\;

ww_led(3) <= \led[3]~output_o\;

ww_led(4) <= \led[4]~output_o\;

ww_led(5) <= \led[5]~output_o\;

ww_led(6) <= \led[6]~output_o\;

ww_led(7) <= \led[7]~output_o\;
END structure;


