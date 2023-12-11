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

-- DATE "11/08/2023 11:14:21"

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

ENTITY 	step1 IS
    PORT (
	I0 : IN std_logic;
	I1 : IN std_logic;
	I2 : IN std_logic;
	I3 : IN std_logic;
	I4 : IN std_logic;
	a : OUT std_logic;
	b : OUT std_logic;
	c : OUT std_logic;
	d : OUT std_logic;
	e : OUT std_logic;
	f : OUT std_logic;
	g : OUT std_logic
	);
END step1;

-- Design Ports Information
-- a	=>  Location: PIN_B18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b	=>  Location: PIN_F15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- c	=>  Location: PIN_A19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d	=>  Location: PIN_B19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- e	=>  Location: PIN_C19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- f	=>  Location: PIN_D19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- g	=>  Location: PIN_G15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- I4	=>  Location: PIN_G5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- I1	=>  Location: PIN_H5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- I2	=>  Location: PIN_H6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- I3	=>  Location: PIN_G4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- I0	=>  Location: PIN_J6,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF step1 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_I0 : std_logic;
SIGNAL ww_I1 : std_logic;
SIGNAL ww_I2 : std_logic;
SIGNAL ww_I3 : std_logic;
SIGNAL ww_I4 : std_logic;
SIGNAL ww_a : std_logic;
SIGNAL ww_b : std_logic;
SIGNAL ww_c : std_logic;
SIGNAL ww_d : std_logic;
SIGNAL ww_e : std_logic;
SIGNAL ww_f : std_logic;
SIGNAL ww_g : std_logic;
SIGNAL \a~output_o\ : std_logic;
SIGNAL \b~output_o\ : std_logic;
SIGNAL \c~output_o\ : std_logic;
SIGNAL \d~output_o\ : std_logic;
SIGNAL \e~output_o\ : std_logic;
SIGNAL \f~output_o\ : std_logic;
SIGNAL \g~output_o\ : std_logic;
SIGNAL \I0~input_o\ : std_logic;
SIGNAL \I1~input_o\ : std_logic;
SIGNAL \I2~input_o\ : std_logic;
SIGNAL \I3~input_o\ : std_logic;
SIGNAL \I4~input_o\ : std_logic;
SIGNAL \WideOr0~0_combout\ : std_logic;
SIGNAL \WideOr0~1_combout\ : std_logic;
SIGNAL \WideOr0~2_combout\ : std_logic;
SIGNAL \WideOr1~0_combout\ : std_logic;
SIGNAL \WideOr1~1_combout\ : std_logic;
SIGNAL \WideOr1~2_combout\ : std_logic;
SIGNAL \WideOr2~0_combout\ : std_logic;
SIGNAL \WideOr2~1_combout\ : std_logic;
SIGNAL \WideOr3~0_combout\ : std_logic;
SIGNAL \WideOr3~1_combout\ : std_logic;
SIGNAL \WideOr3~2_combout\ : std_logic;
SIGNAL \WideOr4~0_combout\ : std_logic;
SIGNAL \WideOr4~1_combout\ : std_logic;
SIGNAL \WideOr5~0_combout\ : std_logic;
SIGNAL \WideOr5~1_combout\ : std_logic;
SIGNAL \WideOr6~1_combout\ : std_logic;
SIGNAL \WideOr6~0_combout\ : std_logic;
SIGNAL \WideOr6~2_combout\ : std_logic;

BEGIN

ww_I0 <= I0;
ww_I1 <= I1;
ww_I2 <= I2;
ww_I3 <= I3;
ww_I4 <= I4;
a <= ww_a;
b <= ww_b;
c <= ww_c;
d <= ww_d;
e <= ww_e;
f <= ww_f;
g <= ww_g;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X32_Y29_N23
\a~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \WideOr0~2_combout\,
	devoe => ww_devoe,
	o => \a~output_o\);

-- Location: IOOBUF_X39_Y29_N16
\b~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \WideOr1~2_combout\,
	devoe => ww_devoe,
	o => \b~output_o\);

-- Location: IOOBUF_X32_Y29_N9
\c~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \WideOr2~1_combout\,
	devoe => ww_devoe,
	o => \c~output_o\);

-- Location: IOOBUF_X32_Y29_N2
\d~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \WideOr3~2_combout\,
	devoe => ww_devoe,
	o => \d~output_o\);

-- Location: IOOBUF_X37_Y29_N23
\e~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \WideOr4~1_combout\,
	devoe => ww_devoe,
	o => \e~output_o\);

-- Location: IOOBUF_X37_Y29_N30
\f~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \WideOr5~1_combout\,
	devoe => ww_devoe,
	o => \f~output_o\);

-- Location: IOOBUF_X39_Y29_N30
\g~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \WideOr6~2_combout\,
	devoe => ww_devoe,
	o => \g~output_o\);

-- Location: IOIBUF_X0_Y24_N1
\I0~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_I0,
	o => \I0~input_o\);

-- Location: IOIBUF_X0_Y27_N1
\I1~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_I1,
	o => \I1~input_o\);

-- Location: IOIBUF_X0_Y25_N22
\I2~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_I2,
	o => \I2~input_o\);

-- Location: IOIBUF_X0_Y23_N8
\I3~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_I3,
	o => \I3~input_o\);

-- Location: IOIBUF_X0_Y27_N22
\I4~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_I4,
	o => \I4~input_o\);

-- Location: LCCOMB_X8_Y27_N8
\WideOr0~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr0~0_combout\ = (\I1~input_o\ & (((\I3~input_o\ & \I4~input_o\)))) # (!\I1~input_o\ & (\I2~input_o\ & (!\I3~input_o\ & !\I4~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000000000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I1~input_o\,
	datab => \I2~input_o\,
	datac => \I3~input_o\,
	datad => \I4~input_o\,
	combout => \WideOr0~0_combout\);

-- Location: LCCOMB_X8_Y27_N10
\WideOr0~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr0~1_combout\ = (\I2~input_o\ & ((\I1~input_o\ & ((!\I4~input_o\))) # (!\I1~input_o\ & (!\I3~input_o\)))) # (!\I2~input_o\ & (!\I4~input_o\ & (\I1~input_o\ $ (\I3~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000010010011110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I1~input_o\,
	datab => \I2~input_o\,
	datac => \I3~input_o\,
	datad => \I4~input_o\,
	combout => \WideOr0~1_combout\);

-- Location: LCCOMB_X8_Y27_N4
\WideOr0~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr0~2_combout\ = (\I0~input_o\ & ((!\WideOr0~1_combout\))) # (!\I0~input_o\ & (\WideOr0~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011000011111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \I0~input_o\,
	datac => \WideOr0~0_combout\,
	datad => \WideOr0~1_combout\,
	combout => \WideOr0~2_combout\);

-- Location: LCCOMB_X8_Y27_N14
\WideOr1~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr1~0_combout\ = (\I3~input_o\ & ((\I1~input_o\ & ((!\I2~input_o\))) # (!\I1~input_o\ & (\I0~input_o\)))) # (!\I3~input_o\ & (\I1~input_o\ $ (((\I0~input_o\) # (\I2~input_o\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101111011100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I3~input_o\,
	datab => \I0~input_o\,
	datac => \I2~input_o\,
	datad => \I1~input_o\,
	combout => \WideOr1~0_combout\);

-- Location: LCCOMB_X8_Y27_N16
\WideOr1~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr1~1_combout\ = (\I3~input_o\ & ((\I0~input_o\ & ((\I1~input_o\))) # (!\I0~input_o\ & (\I2~input_o\)))) # (!\I3~input_o\ & (\I2~input_o\ & (\I0~input_o\ $ (\I1~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011100001100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I3~input_o\,
	datab => \I0~input_o\,
	datac => \I2~input_o\,
	datad => \I1~input_o\,
	combout => \WideOr1~1_combout\);

-- Location: LCCOMB_X8_Y27_N26
\WideOr1~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr1~2_combout\ = (\I4~input_o\ & (\WideOr1~0_combout\)) # (!\I4~input_o\ & ((\WideOr1~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001111000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \I4~input_o\,
	datac => \WideOr1~0_combout\,
	datad => \WideOr1~1_combout\,
	combout => \WideOr1~2_combout\);

-- Location: LCCOMB_X8_Y27_N20
\WideOr2~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr2~0_combout\ = (\I3~input_o\ & (\I2~input_o\ $ (((\I0~input_o\ & !\I1~input_o\))))) # (!\I3~input_o\ & (!\I0~input_o\ & (!\I2~input_o\ & \I1~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000100101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I3~input_o\,
	datab => \I0~input_o\,
	datac => \I2~input_o\,
	datad => \I1~input_o\,
	combout => \WideOr2~0_combout\);

-- Location: LCCOMB_X8_Y27_N6
\WideOr2~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr2~1_combout\ = (\I4~input_o\ & ((\I2~input_o\ & (!\I1~input_o\)) # (!\I2~input_o\ & ((\WideOr2~0_combout\))))) # (!\I4~input_o\ & (\WideOr2~0_combout\ & ((\I1~input_o\) # (\I2~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111111001000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I1~input_o\,
	datab => \I4~input_o\,
	datac => \I2~input_o\,
	datad => \WideOr2~0_combout\,
	combout => \WideOr2~1_combout\);

-- Location: LCCOMB_X8_Y27_N28
\WideOr3~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr3~0_combout\ = (\I1~input_o\ & (!\I0~input_o\ & (\I3~input_o\))) # (!\I1~input_o\ & (!\I3~input_o\ & (\I0~input_o\ $ (\I4~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010000100100100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I1~input_o\,
	datab => \I0~input_o\,
	datac => \I3~input_o\,
	datad => \I4~input_o\,
	combout => \WideOr3~0_combout\);

-- Location: LCCOMB_X8_Y27_N22
\WideOr3~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr3~1_combout\ = (\I1~input_o\ & (((\I3~input_o\ & \I4~input_o\)) # (!\I0~input_o\))) # (!\I1~input_o\ & (\I4~input_o\ $ (((\I0~input_o\) # (\I3~input_o\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010001101110110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I1~input_o\,
	datab => \I0~input_o\,
	datac => \I3~input_o\,
	datad => \I4~input_o\,
	combout => \WideOr3~1_combout\);

-- Location: LCCOMB_X31_Y27_N16
\WideOr3~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr3~2_combout\ = (\I2~input_o\ & ((!\WideOr3~1_combout\))) # (!\I2~input_o\ & (\WideOr3~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \WideOr3~0_combout\,
	datac => \I2~input_o\,
	datad => \WideOr3~1_combout\,
	combout => \WideOr3~2_combout\);

-- Location: LCCOMB_X8_Y27_N0
\WideOr4~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr4~0_combout\ = (\I3~input_o\ & (\I0~input_o\ & (\I2~input_o\ $ (!\I1~input_o\)))) # (!\I3~input_o\ & ((\I0~input_o\) # ((\I2~input_o\ & !\I1~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100010001011100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I3~input_o\,
	datab => \I0~input_o\,
	datac => \I2~input_o\,
	datad => \I1~input_o\,
	combout => \WideOr4~0_combout\);

-- Location: LCCOMB_X8_Y27_N18
\WideOr4~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr4~1_combout\ = (\I4~input_o\ & (\I2~input_o\ & (\I3~input_o\ $ (!\WideOr4~0_combout\)))) # (!\I4~input_o\ & (\WideOr4~0_combout\ & ((!\I2~input_o\) # (!\I3~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001001101000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I3~input_o\,
	datab => \I4~input_o\,
	datac => \I2~input_o\,
	datad => \WideOr4~0_combout\,
	combout => \WideOr4~1_combout\);

-- Location: LCCOMB_X8_Y27_N12
\WideOr5~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr5~0_combout\ = (\I4~input_o\ & ((\I0~input_o\ & (\I1~input_o\)) # (!\I0~input_o\ & ((\I3~input_o\))))) # (!\I4~input_o\ & ((\I1~input_o\ & ((!\I3~input_o\))) # (!\I1~input_o\ & (\I0~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011100001001110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I1~input_o\,
	datab => \I0~input_o\,
	datac => \I3~input_o\,
	datad => \I4~input_o\,
	combout => \WideOr5~0_combout\);

-- Location: LCCOMB_X8_Y27_N30
\WideOr5~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr5~1_combout\ = (\WideOr5~0_combout\ & (\I2~input_o\ $ (((\I4~input_o\) # (!\I3~input_o\))))) # (!\WideOr5~0_combout\ & (\I2~input_o\ & (\I3~input_o\ & \I4~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110001010000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \WideOr5~0_combout\,
	datab => \I2~input_o\,
	datac => \I3~input_o\,
	datad => \I4~input_o\,
	combout => \WideOr5~1_combout\);

-- Location: LCCOMB_X8_Y27_N2
\WideOr6~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr6~1_combout\ = (\I1~input_o\ & ((\I0~input_o\) # ((\I3~input_o\) # (!\I4~input_o\)))) # (!\I1~input_o\ & ((\I3~input_o\ $ (\I4~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010110111111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I1~input_o\,
	datab => \I0~input_o\,
	datac => \I3~input_o\,
	datad => \I4~input_o\,
	combout => \WideOr6~1_combout\);

-- Location: LCCOMB_X8_Y27_N24
\WideOr6~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr6~0_combout\ = (\I0~input_o\ & (\I1~input_o\ & (!\I3~input_o\ & !\I4~input_o\))) # (!\I0~input_o\ & (\I3~input_o\ & (\I1~input_o\ $ (!\I4~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010000000011000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I1~input_o\,
	datab => \I0~input_o\,
	datac => \I3~input_o\,
	datad => \I4~input_o\,
	combout => \WideOr6~0_combout\);

-- Location: LCCOMB_X31_Y27_N18
\WideOr6~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr6~2_combout\ = (\I2~input_o\ & ((\WideOr6~0_combout\))) # (!\I2~input_o\ & (!\WideOr6~1_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001100000011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \WideOr6~1_combout\,
	datac => \I2~input_o\,
	datad => \WideOr6~0_combout\,
	combout => \WideOr6~2_combout\);

ww_a <= \a~output_o\;

ww_b <= \b~output_o\;

ww_c <= \c~output_o\;

ww_d <= \d~output_o\;

ww_e <= \e~output_o\;

ww_f <= \f~output_o\;

ww_g <= \g~output_o\;
END structure;


