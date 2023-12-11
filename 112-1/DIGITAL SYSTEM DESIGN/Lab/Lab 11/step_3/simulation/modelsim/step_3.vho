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

-- DATE "12/08/2023 14:13:19"

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

ENTITY 	step_3 IS
    PORT (
	EO : IN std_logic;
	clk : IN std_logic;
	reset : IN std_logic;
	led : OUT std_logic_vector(0 TO 6)
	);
END step_3;

-- Design Ports Information
-- led[6]	=>  Location: PIN_G15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- led[5]	=>  Location: PIN_D19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- led[4]	=>  Location: PIN_C19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- led[3]	=>  Location: PIN_B19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- led[2]	=>  Location: PIN_A19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- led[1]	=>  Location: PIN_F15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- led[0]	=>  Location: PIN_B18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reset	=>  Location: PIN_H2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- EO	=>  Location: PIN_J6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clk	=>  Location: PIN_G3,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF step_3 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_EO : std_logic;
SIGNAL ww_clk : std_logic;
SIGNAL ww_reset : std_logic;
SIGNAL ww_led : std_logic_vector(0 TO 6);
SIGNAL \led[6]~output_o\ : std_logic;
SIGNAL \led[5]~output_o\ : std_logic;
SIGNAL \led[4]~output_o\ : std_logic;
SIGNAL \led[3]~output_o\ : std_logic;
SIGNAL \led[2]~output_o\ : std_logic;
SIGNAL \led[1]~output_o\ : std_logic;
SIGNAL \led[0]~output_o\ : std_logic;
SIGNAL \EO~input_o\ : std_logic;
SIGNAL \reset~input_o\ : std_logic;
SIGNAL \count~1_combout\ : std_logic;
SIGNAL \clk~input_o\ : std_logic;
SIGNAL \count~3_combout\ : std_logic;
SIGNAL \count~_emulated_q\ : std_logic;
SIGNAL \count~2_combout\ : std_logic;
SIGNAL \ALT_INV_clk~input_o\ : std_logic;

BEGIN

ww_EO <= EO;
ww_clk <= clk;
ww_reset <= reset;
led <= ww_led;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_clk~input_o\ <= NOT \clk~input_o\;

-- Location: IOOBUF_X39_Y29_N30
\led[6]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \led[6]~output_o\);

-- Location: IOOBUF_X37_Y29_N30
\led[5]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \count~2_combout\,
	devoe => ww_devoe,
	o => \led[5]~output_o\);

-- Location: IOOBUF_X37_Y29_N23
\led[4]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \count~2_combout\,
	devoe => ww_devoe,
	o => \led[4]~output_o\);

-- Location: IOOBUF_X32_Y29_N2
\led[3]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \count~2_combout\,
	devoe => ww_devoe,
	o => \led[3]~output_o\);

-- Location: IOOBUF_X32_Y29_N9
\led[2]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \led[2]~output_o\);

-- Location: IOOBUF_X39_Y29_N16
\led[1]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \led[1]~output_o\);

-- Location: IOOBUF_X32_Y29_N23
\led[0]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \count~2_combout\,
	devoe => ww_devoe,
	o => \led[0]~output_o\);

-- Location: IOIBUF_X0_Y24_N1
\EO~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_EO,
	o => \EO~input_o\);

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

-- Location: LCCOMB_X1_Y21_N24
\count~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \count~1_combout\ = (\reset~input_o\ & ((\count~1_combout\))) # (!\reset~input_o\ & (\EO~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \EO~input_o\,
	datab => \count~1_combout\,
	datad => \reset~input_o\,
	combout => \count~1_combout\);

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

-- Location: LCCOMB_X1_Y21_N12
\count~3\ : cycloneiii_lcell_comb
-- Equation(s):
-- \count~3_combout\ = \count~1_combout\ $ (\count~2_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \count~1_combout\,
	datad => \count~2_combout\,
	combout => \count~3_combout\);

-- Location: FF_X1_Y21_N13
\count~_emulated\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_clk~input_o\,
	d => \count~3_combout\,
	clrn => \reset~input_o\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \count~_emulated_q\);

-- Location: LCCOMB_X1_Y21_N18
\count~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \count~2_combout\ = (\reset~input_o\ & ((\count~1_combout\ $ (\count~_emulated_q\)))) # (!\reset~input_o\ & (\EO~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010111011100010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \EO~input_o\,
	datab => \reset~input_o\,
	datac => \count~1_combout\,
	datad => \count~_emulated_q\,
	combout => \count~2_combout\);

ww_led(6) <= \led[6]~output_o\;

ww_led(5) <= \led[5]~output_o\;

ww_led(4) <= \led[4]~output_o\;

ww_led(3) <= \led[3]~output_o\;

ww_led(2) <= \led[2]~output_o\;

ww_led(1) <= \led[1]~output_o\;

ww_led(0) <= \led[0]~output_o\;
END structure;


