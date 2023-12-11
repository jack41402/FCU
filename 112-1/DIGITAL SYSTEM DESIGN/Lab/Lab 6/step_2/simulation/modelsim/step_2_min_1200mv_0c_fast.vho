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

-- DATE "10/31/2023 21:50:18"

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
	F_SOP : OUT std_logic;
	B : IN std_logic;
	C : IN std_logic;
	D : IN std_logic;
	A : IN std_logic;
	F_POS : OUT std_logic
	);
END step_2;

-- Design Ports Information
-- F_SOP	=>  Location: PIN_J1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F_POS	=>  Location: PIN_J3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A	=>  Location: PIN_G4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D	=>  Location: PIN_J6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- C	=>  Location: PIN_H5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B	=>  Location: PIN_H6,	 I/O Standard: 2.5 V,	 Current Strength: Default


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
SIGNAL ww_F_SOP : std_logic;
SIGNAL ww_B : std_logic;
SIGNAL ww_C : std_logic;
SIGNAL ww_D : std_logic;
SIGNAL ww_A : std_logic;
SIGNAL ww_F_POS : std_logic;
SIGNAL \F_SOP~output_o\ : std_logic;
SIGNAL \F_POS~output_o\ : std_logic;
SIGNAL \A~input_o\ : std_logic;
SIGNAL \D~input_o\ : std_logic;
SIGNAL \B~input_o\ : std_logic;
SIGNAL \C~input_o\ : std_logic;
SIGNAL \inst15~0_combout\ : std_logic;

BEGIN

F_SOP <= ww_F_SOP;
ww_B <= B;
ww_C <= C;
ww_D <= D;
ww_A <= A;
F_POS <= ww_F_POS;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X0_Y20_N9
\F_SOP~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst15~0_combout\,
	devoe => ww_devoe,
	o => \F_SOP~output_o\);

-- Location: IOOBUF_X0_Y21_N23
\F_POS~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst15~0_combout\,
	devoe => ww_devoe,
	o => \F_POS~output_o\);

-- Location: IOIBUF_X0_Y23_N8
\A~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A,
	o => \A~input_o\);

-- Location: IOIBUF_X0_Y24_N1
\D~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_D,
	o => \D~input_o\);

-- Location: IOIBUF_X0_Y25_N22
\B~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B,
	o => \B~input_o\);

-- Location: IOIBUF_X0_Y27_N1
\C~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_C,
	o => \C~input_o\);

-- Location: LCCOMB_X1_Y24_N8
\inst15~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst15~0_combout\ = (\B~input_o\ & (((!\D~input_o\ & !\C~input_o\)))) # (!\B~input_o\ & (((!\C~input_o\)) # (!\A~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000010100111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A~input_o\,
	datab => \D~input_o\,
	datac => \B~input_o\,
	datad => \C~input_o\,
	combout => \inst15~0_combout\);

ww_F_SOP <= \F_SOP~output_o\;

ww_F_POS <= \F_POS~output_o\;
END structure;


