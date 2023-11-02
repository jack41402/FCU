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

-- DATE "11/01/2023 11:09:42"

-- 
-- Device: Altera EP3C16F484C6 Package FBGA484
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIII;
LIBRARY IEEE;
USE CYCLONEIII.CYCLONEIII_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	step_2 IS
    PORT (
	A : OUT std_logic;
	I : IN std_logic;
	P : IN std_logic;
	D : IN std_logic;
	G : IN std_logic;
	B : OUT std_logic;
	F : OUT std_logic
	);
END step_2;

-- Design Ports Information
-- A	=>  Location: PIN_J1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B	=>  Location: PIN_J2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F	=>  Location: PIN_J3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- I	=>  Location: PIN_G4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D	=>  Location: PIN_H6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- G	=>  Location: PIN_H5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- P	=>  Location: PIN_J6,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF step_2 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_A : std_logic;
SIGNAL ww_I : std_logic;
SIGNAL ww_P : std_logic;
SIGNAL ww_D : std_logic;
SIGNAL ww_G : std_logic;
SIGNAL ww_B : std_logic;
SIGNAL ww_F : std_logic;
SIGNAL \A~output_o\ : std_logic;
SIGNAL \B~output_o\ : std_logic;
SIGNAL \F~output_o\ : std_logic;
SIGNAL \P~input_o\ : std_logic;
SIGNAL \I~input_o\ : std_logic;
SIGNAL \G~input_o\ : std_logic;
SIGNAL \D~input_o\ : std_logic;
SIGNAL \inst8~0_combout\ : std_logic;
SIGNAL \inst10~0_combout\ : std_logic;
SIGNAL \inst15~0_combout\ : std_logic;

BEGIN

A <= ww_A;
ww_I <= I;
ww_P <= P;
ww_D <= D;
ww_G <= G;
B <= ww_B;
F <= ww_F;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X0_Y20_N9
\A~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst8~0_combout\,
	devoe => ww_devoe,
	o => \A~output_o\);

-- Location: IOOBUF_X0_Y20_N2
\B~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst10~0_combout\,
	devoe => ww_devoe,
	o => \B~output_o\);

-- Location: IOOBUF_X0_Y21_N23
\F~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst15~0_combout\,
	devoe => ww_devoe,
	o => \F~output_o\);

-- Location: IOIBUF_X0_Y24_N1
\P~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_P,
	o => \P~input_o\);

-- Location: IOIBUF_X0_Y23_N8
\I~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_I,
	o => \I~input_o\);

-- Location: IOIBUF_X0_Y27_N1
\G~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_G,
	o => \G~input_o\);

-- Location: IOIBUF_X0_Y25_N22
\D~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_D,
	o => \D~input_o\);

-- Location: LCCOMB_X4_Y20_N0
\inst8~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst8~0_combout\ = (\I~input_o\ & ((\P~input_o\ & ((\G~input_o\) # (\D~input_o\))) # (!\P~input_o\ & (\G~input_o\ & \D~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100100010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \P~input_o\,
	datab => \I~input_o\,
	datac => \G~input_o\,
	datad => \D~input_o\,
	combout => \inst8~0_combout\);

-- Location: LCCOMB_X4_Y20_N2
\inst10~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst10~0_combout\ = (!\I~input_o\ & ((\P~input_o\) # ((\G~input_o\) # (\D~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100110010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \P~input_o\,
	datab => \I~input_o\,
	datac => \G~input_o\,
	datad => \D~input_o\,
	combout => \inst10~0_combout\);

-- Location: LCCOMB_X4_Y20_N4
\inst15~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst15~0_combout\ = (\P~input_o\ & (\I~input_o\ & (!\G~input_o\ & !\D~input_o\))) # (!\P~input_o\ & ((\I~input_o\ & ((!\D~input_o\) # (!\G~input_o\))) # (!\I~input_o\ & (!\G~input_o\ & !\D~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000010001001101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \P~input_o\,
	datab => \I~input_o\,
	datac => \G~input_o\,
	datad => \D~input_o\,
	combout => \inst15~0_combout\);

ww_A <= \A~output_o\;

ww_B <= \B~output_o\;

ww_F <= \F~output_o\;
END structure;


