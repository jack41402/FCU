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

-- DATE "12/06/2023 11:53:18"

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

ENTITY 	step2 IS
    PORT (
	I0 : IN std_logic;
	I1 : IN std_logic;
	I2 : IN std_logic;
	I3 : IN std_logic;
	I4 : IN std_logic;
	I5 : IN std_logic;
	I6 : IN std_logic;
	I7 : IN std_logic;
	a : BUFFER std_logic;
	b : BUFFER std_logic;
	c : BUFFER std_logic;
	d : BUFFER std_logic;
	e : BUFFER std_logic;
	f : BUFFER std_logic;
	g : BUFFER std_logic
	);
END step2;

-- Design Ports Information
-- a	=>  Location: PIN_B18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b	=>  Location: PIN_F15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- c	=>  Location: PIN_A19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d	=>  Location: PIN_B19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- e	=>  Location: PIN_C19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- f	=>  Location: PIN_D19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- g	=>  Location: PIN_G15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- I1	=>  Location: PIN_H5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- I2	=>  Location: PIN_H6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- I3	=>  Location: PIN_G4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- I4	=>  Location: PIN_G5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- I7	=>  Location: PIN_E3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- I5	=>  Location: PIN_J7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- I6	=>  Location: PIN_H7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- I0	=>  Location: PIN_J6,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF step2 IS
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
SIGNAL ww_I5 : std_logic;
SIGNAL ww_I6 : std_logic;
SIGNAL ww_I7 : std_logic;
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
SIGNAL \I5~input_o\ : std_logic;
SIGNAL \I7~input_o\ : std_logic;
SIGNAL \I6~input_o\ : std_logic;
SIGNAL \WideOr0~1_combout\ : std_logic;
SIGNAL \I3~input_o\ : std_logic;
SIGNAL \I1~input_o\ : std_logic;
SIGNAL \I2~input_o\ : std_logic;
SIGNAL \I4~input_o\ : std_logic;
SIGNAL \WideOr0~0_combout\ : std_logic;
SIGNAL \WideOr0~2_combout\ : std_logic;
SIGNAL \WideOr1~0_combout\ : std_logic;
SIGNAL \WideOr4~0_combout\ : std_logic;
SIGNAL \led~0_combout\ : std_logic;
SIGNAL \WideOr2~0_combout\ : std_logic;
SIGNAL \WideOr2~1_combout\ : std_logic;
SIGNAL \WideOr3~0_combout\ : std_logic;
SIGNAL \WideOr3~1_combout\ : std_logic;
SIGNAL \WideOr3~2_combout\ : std_logic;
SIGNAL \WideOr4~1_combout\ : std_logic;
SIGNAL \WideOr4~2_combout\ : std_logic;
SIGNAL \WideOr5~0_combout\ : std_logic;
SIGNAL \WideOr5~1_combout\ : std_logic;
SIGNAL \WideOr5~2_combout\ : std_logic;

BEGIN

ww_I0 <= I0;
ww_I1 <= I1;
ww_I2 <= I2;
ww_I3 <= I3;
ww_I4 <= I4;
ww_I5 <= I5;
ww_I6 <= I6;
ww_I7 <= I7;
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
	i => \WideOr1~0_combout\,
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
	i => \led~0_combout\,
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
	i => \WideOr2~1_combout\,
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
	i => \WideOr3~2_combout\,
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
	i => \WideOr4~2_combout\,
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
	i => \WideOr5~2_combout\,
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

-- Location: IOIBUF_X0_Y22_N15
\I5~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_I5,
	o => \I5~input_o\);

-- Location: IOIBUF_X0_Y26_N8
\I7~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_I7,
	o => \I7~input_o\);

-- Location: IOIBUF_X0_Y25_N15
\I6~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_I6,
	o => \I6~input_o\);

-- Location: LCCOMB_X7_Y24_N26
\WideOr0~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr0~1_combout\ = (!\I5~input_o\ & (!\I7~input_o\ & !\I6~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \I5~input_o\,
	datac => \I7~input_o\,
	datad => \I6~input_o\,
	combout => \WideOr0~1_combout\);

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

-- Location: LCCOMB_X7_Y24_N16
\WideOr0~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr0~0_combout\ = (\I4~input_o\) # ((!\I3~input_o\ & (\I1~input_o\ & !\I2~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I3~input_o\,
	datab => \I1~input_o\,
	datac => \I2~input_o\,
	datad => \I4~input_o\,
	combout => \WideOr0~0_combout\);

-- Location: LCCOMB_X7_Y24_N12
\WideOr0~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr0~2_combout\ = ((\WideOr0~1_combout\ & \WideOr0~0_combout\)) # (!\I0~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I0~input_o\,
	datac => \WideOr0~1_combout\,
	datad => \WideOr0~0_combout\,
	combout => \WideOr0~2_combout\);

-- Location: LCCOMB_X7_Y24_N14
\WideOr1~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr1~0_combout\ = (\I0~input_o\ & (!\I7~input_o\ & ((\I5~input_o\) # (\I6~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101000001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I0~input_o\,
	datab => \I5~input_o\,
	datac => \I7~input_o\,
	datad => \I6~input_o\,
	combout => \WideOr1~0_combout\);

-- Location: LCCOMB_X7_Y24_N24
\WideOr4~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr4~0_combout\ = (\I0~input_o\ & (!\I5~input_o\ & (!\I7~input_o\ & !\I6~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I0~input_o\,
	datab => \I5~input_o\,
	datac => \I7~input_o\,
	datad => \I6~input_o\,
	combout => \WideOr4~0_combout\);

-- Location: LCCOMB_X7_Y24_N2
\led~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \led~0_combout\ = (!\I3~input_o\ & (!\I4~input_o\ & (\I2~input_o\ & \WideOr4~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I3~input_o\,
	datab => \I4~input_o\,
	datac => \I2~input_o\,
	datad => \WideOr4~0_combout\,
	combout => \led~0_combout\);

-- Location: LCCOMB_X7_Y24_N20
\WideOr2~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr2~0_combout\ = (\I5~input_o\) # ((!\I4~input_o\ & ((\I3~input_o\) # (\I2~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011111110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I3~input_o\,
	datab => \I5~input_o\,
	datac => \I2~input_o\,
	datad => \I4~input_o\,
	combout => \WideOr2~0_combout\);

-- Location: LCCOMB_X7_Y24_N6
\WideOr2~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr2~1_combout\ = (\I0~input_o\ & ((\I7~input_o\) # ((!\I6~input_o\ & !\WideOr2~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000010100010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I0~input_o\,
	datab => \I6~input_o\,
	datac => \I7~input_o\,
	datad => \WideOr2~0_combout\,
	combout => \WideOr2~1_combout\);

-- Location: LCCOMB_X7_Y24_N8
\WideOr3~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr3~0_combout\ = (\I3~input_o\) # ((\I4~input_o\) # ((\I1~input_o\ & !\I2~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I3~input_o\,
	datab => \I1~input_o\,
	datac => \I2~input_o\,
	datad => \I4~input_o\,
	combout => \WideOr3~0_combout\);

-- Location: LCCOMB_X7_Y24_N10
\WideOr3~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr3~1_combout\ = (\I0~input_o\ & (!\I6~input_o\ & ((\I5~input_o\) # (\WideOr3~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000010101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I0~input_o\,
	datab => \I5~input_o\,
	datac => \WideOr3~0_combout\,
	datad => \I6~input_o\,
	combout => \WideOr3~1_combout\);

-- Location: LCCOMB_X7_Y24_N4
\WideOr3~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr3~2_combout\ = (\WideOr3~1_combout\) # ((\I0~input_o\ & \I7~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I0~input_o\,
	datac => \I7~input_o\,
	datad => \WideOr3~1_combout\,
	combout => \WideOr3~2_combout\);

-- Location: LCCOMB_X7_Y24_N30
\WideOr4~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr4~1_combout\ = (!\I4~input_o\ & ((\I3~input_o\) # ((\I1~input_o\) # (\I2~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I3~input_o\,
	datab => \I1~input_o\,
	datac => \I2~input_o\,
	datad => \I4~input_o\,
	combout => \WideOr4~1_combout\);

-- Location: LCCOMB_X7_Y24_N0
\WideOr4~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr4~2_combout\ = (\WideOr4~0_combout\ & \WideOr4~1_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \WideOr4~0_combout\,
	datac => \WideOr4~1_combout\,
	combout => \WideOr4~2_combout\);

-- Location: LCCOMB_X7_Y24_N18
\WideOr5~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr5~0_combout\ = (!\I3~input_o\ & (!\I6~input_o\ & (!\I5~input_o\ & !\I4~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I3~input_o\,
	datab => \I6~input_o\,
	datac => \I5~input_o\,
	datad => \I4~input_o\,
	combout => \WideOr5~0_combout\);

-- Location: LCCOMB_X7_Y24_N28
\WideOr5~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr5~1_combout\ = (!\I2~input_o\ & \I1~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \I2~input_o\,
	datad => \I1~input_o\,
	combout => \WideOr5~1_combout\);

-- Location: LCCOMB_X7_Y24_N22
\WideOr5~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr5~2_combout\ = ((\I7~input_o\) # ((\WideOr5~0_combout\ & \WideOr5~1_combout\))) # (!\I0~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110111110101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \I0~input_o\,
	datab => \WideOr5~0_combout\,
	datac => \I7~input_o\,
	datad => \WideOr5~1_combout\,
	combout => \WideOr5~2_combout\);

ww_a <= \a~output_o\;

ww_b <= \b~output_o\;

ww_c <= \c~output_o\;

ww_d <= \d~output_o\;

ww_e <= \e~output_o\;

ww_f <= \f~output_o\;

ww_g <= \g~output_o\;
END structure;


