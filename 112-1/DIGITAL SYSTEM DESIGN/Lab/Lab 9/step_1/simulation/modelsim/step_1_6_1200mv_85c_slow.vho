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

-- DATE "11/22/2023 02:15:09"

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
	v : IN std_logic_vector(3 DOWNTO 0);
	d0 : OUT std_logic_vector(0 TO 6);
	d1 : OUT std_logic_vector(0 TO 6)
	);
END step1;

-- Design Ports Information
-- d0[6]	=>  Location: PIN_F14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d0[5]	=>  Location: PIN_B17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d0[4]	=>  Location: PIN_A17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d0[3]	=>  Location: PIN_E15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d0[2]	=>  Location: PIN_B16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d0[1]	=>  Location: PIN_A16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d0[0]	=>  Location: PIN_D15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d1[6]	=>  Location: PIN_G15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d1[5]	=>  Location: PIN_D19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d1[4]	=>  Location: PIN_C19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d1[3]	=>  Location: PIN_B19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d1[2]	=>  Location: PIN_A19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d1[1]	=>  Location: PIN_F15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d1[0]	=>  Location: PIN_B18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- v[0]	=>  Location: PIN_J6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- v[1]	=>  Location: PIN_H5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- v[2]	=>  Location: PIN_H6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- v[3]	=>  Location: PIN_G4,	 I/O Standard: 2.5 V,	 Current Strength: Default


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
SIGNAL ww_v : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_d0 : std_logic_vector(0 TO 6);
SIGNAL ww_d1 : std_logic_vector(0 TO 6);
SIGNAL \d0[6]~output_o\ : std_logic;
SIGNAL \d0[5]~output_o\ : std_logic;
SIGNAL \d0[4]~output_o\ : std_logic;
SIGNAL \d0[3]~output_o\ : std_logic;
SIGNAL \d0[2]~output_o\ : std_logic;
SIGNAL \d0[1]~output_o\ : std_logic;
SIGNAL \d0[0]~output_o\ : std_logic;
SIGNAL \d1[6]~output_o\ : std_logic;
SIGNAL \d1[5]~output_o\ : std_logic;
SIGNAL \d1[4]~output_o\ : std_logic;
SIGNAL \d1[3]~output_o\ : std_logic;
SIGNAL \d1[2]~output_o\ : std_logic;
SIGNAL \d1[1]~output_o\ : std_logic;
SIGNAL \d1[0]~output_o\ : std_logic;
SIGNAL \v[2]~input_o\ : std_logic;
SIGNAL \v[0]~input_o\ : std_logic;
SIGNAL \v[3]~input_o\ : std_logic;
SIGNAL \v[1]~input_o\ : std_logic;
SIGNAL \WideOr5~0_combout\ : std_logic;
SIGNAL \WideOr4~0_combout\ : std_logic;
SIGNAL \WideOr3~0_combout\ : std_logic;
SIGNAL \WideOr2~0_combout\ : std_logic;
SIGNAL \d0~0_combout\ : std_logic;
SIGNAL \WideOr1~0_combout\ : std_logic;
SIGNAL \WideOr0~0_combout\ : std_logic;
SIGNAL \WideOr6~0_combout\ : std_logic;
SIGNAL \ALT_INV_WideOr6~0_combout\ : std_logic;
SIGNAL \ALT_INV_WideOr5~0_combout\ : std_logic;

BEGIN

ww_v <= v;
d0 <= ww_d0;
d1 <= ww_d1;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_WideOr6~0_combout\ <= NOT \WideOr6~0_combout\;
\ALT_INV_WideOr5~0_combout\ <= NOT \WideOr5~0_combout\;

-- Location: IOOBUF_X37_Y29_N2
\d0[6]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_WideOr5~0_combout\,
	devoe => ww_devoe,
	o => \d0[6]~output_o\);

-- Location: IOOBUF_X30_Y29_N23
\d0[5]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \WideOr4~0_combout\,
	devoe => ww_devoe,
	o => \d0[5]~output_o\);

-- Location: IOOBUF_X30_Y29_N16
\d0[4]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \WideOr3~0_combout\,
	devoe => ww_devoe,
	o => \d0[4]~output_o\);

-- Location: IOOBUF_X30_Y29_N2
\d0[3]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \WideOr2~0_combout\,
	devoe => ww_devoe,
	o => \d0[3]~output_o\);

-- Location: IOOBUF_X28_Y29_N2
\d0[2]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \d0~0_combout\,
	devoe => ww_devoe,
	o => \d0[2]~output_o\);

-- Location: IOOBUF_X30_Y29_N30
\d0[1]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \WideOr1~0_combout\,
	devoe => ww_devoe,
	o => \d0[1]~output_o\);

-- Location: IOOBUF_X32_Y29_N30
\d0[0]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \WideOr0~0_combout\,
	devoe => ww_devoe,
	o => \d0[0]~output_o\);

-- Location: IOOBUF_X39_Y29_N30
\d1[6]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \d1[6]~output_o\);

-- Location: IOOBUF_X37_Y29_N30
\d1[5]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_WideOr6~0_combout\,
	devoe => ww_devoe,
	o => \d1[5]~output_o\);

-- Location: IOOBUF_X37_Y29_N23
\d1[4]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_WideOr6~0_combout\,
	devoe => ww_devoe,
	o => \d1[4]~output_o\);

-- Location: IOOBUF_X32_Y29_N2
\d1[3]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_WideOr6~0_combout\,
	devoe => ww_devoe,
	o => \d1[3]~output_o\);

-- Location: IOOBUF_X32_Y29_N9
\d1[2]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \d1[2]~output_o\);

-- Location: IOOBUF_X39_Y29_N16
\d1[1]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \d1[1]~output_o\);

-- Location: IOOBUF_X32_Y29_N23
\d1[0]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_WideOr6~0_combout\,
	devoe => ww_devoe,
	o => \d1[0]~output_o\);

-- Location: IOIBUF_X0_Y25_N22
\v[2]~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_v(2),
	o => \v[2]~input_o\);

-- Location: IOIBUF_X0_Y24_N1
\v[0]~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_v(0),
	o => \v[0]~input_o\);

-- Location: IOIBUF_X0_Y23_N8
\v[3]~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_v(3),
	o => \v[3]~input_o\);

-- Location: IOIBUF_X0_Y27_N1
\v[1]~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_v(1),
	o => \v[1]~input_o\);

-- Location: LCCOMB_X14_Y28_N24
\WideOr5~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr5~0_combout\ = (\v[2]~input_o\ & (((\v[3]~input_o\) # (!\v[1]~input_o\)) # (!\v[0]~input_o\))) # (!\v[2]~input_o\ & ((\v[3]~input_o\ $ (\v[1]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010011111111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \v[2]~input_o\,
	datab => \v[0]~input_o\,
	datac => \v[3]~input_o\,
	datad => \v[1]~input_o\,
	combout => \WideOr5~0_combout\);

-- Location: LCCOMB_X14_Y28_N10
\WideOr4~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr4~0_combout\ = (\v[2]~input_o\ & (((\v[3]~input_o\ & !\v[1]~input_o\)))) # (!\v[2]~input_o\ & ((\v[0]~input_o\ & ((\v[1]~input_o\) # (!\v[3]~input_o\))) # (!\v[0]~input_o\ & (!\v[3]~input_o\ & \v[1]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100010110100100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \v[2]~input_o\,
	datab => \v[0]~input_o\,
	datac => \v[3]~input_o\,
	datad => \v[1]~input_o\,
	combout => \WideOr4~0_combout\);

-- Location: LCCOMB_X14_Y28_N20
\WideOr3~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr3~0_combout\ = (\v[0]~input_o\) # ((\v[2]~input_o\ & (\v[3]~input_o\ $ (!\v[1]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110110011001110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \v[2]~input_o\,
	datab => \v[0]~input_o\,
	datac => \v[3]~input_o\,
	datad => \v[1]~input_o\,
	combout => \WideOr3~0_combout\);

-- Location: LCCOMB_X14_Y28_N6
\WideOr2~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr2~0_combout\ = (\v[2]~input_o\ & ((\v[0]~input_o\ & (!\v[3]~input_o\ & \v[1]~input_o\)) # (!\v[0]~input_o\ & (\v[3]~input_o\ $ (!\v[1]~input_o\))))) # (!\v[2]~input_o\ & (\v[0]~input_o\ & (\v[3]~input_o\ $ (!\v[1]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110100000000110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \v[2]~input_o\,
	datab => \v[0]~input_o\,
	datac => \v[3]~input_o\,
	datad => \v[1]~input_o\,
	combout => \WideOr2~0_combout\);

-- Location: LCCOMB_X14_Y28_N16
\d0~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \d0~0_combout\ = (!\v[0]~input_o\ & ((\v[2]~input_o\ & (\v[3]~input_o\ & !\v[1]~input_o\)) # (!\v[2]~input_o\ & (!\v[3]~input_o\ & \v[1]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000100100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \v[2]~input_o\,
	datab => \v[0]~input_o\,
	datac => \v[3]~input_o\,
	datad => \v[1]~input_o\,
	combout => \d0~0_combout\);

-- Location: LCCOMB_X14_Y28_N2
\WideOr1~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr1~0_combout\ = (\v[2]~input_o\ & ((\v[0]~input_o\ & (\v[3]~input_o\ $ (!\v[1]~input_o\))) # (!\v[0]~input_o\ & (!\v[3]~input_o\ & \v[1]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000001000001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \v[2]~input_o\,
	datab => \v[0]~input_o\,
	datac => \v[3]~input_o\,
	datad => \v[1]~input_o\,
	combout => \WideOr1~0_combout\);

-- Location: LCCOMB_X14_Y28_N4
\WideOr0~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr0~0_combout\ = (\v[2]~input_o\ & (!\v[0]~input_o\ & (\v[3]~input_o\ $ (!\v[1]~input_o\)))) # (!\v[2]~input_o\ & (\v[0]~input_o\ & (\v[3]~input_o\ $ (!\v[1]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110000000000110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \v[2]~input_o\,
	datab => \v[0]~input_o\,
	datac => \v[3]~input_o\,
	datad => \v[1]~input_o\,
	combout => \WideOr0~0_combout\);

-- Location: LCCOMB_X14_Y28_N22
\WideOr6~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr6~0_combout\ = ((!\v[2]~input_o\ & !\v[1]~input_o\)) # (!\v[3]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111101011111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \v[2]~input_o\,
	datac => \v[3]~input_o\,
	datad => \v[1]~input_o\,
	combout => \WideOr6~0_combout\);

ww_d0(6) <= \d0[6]~output_o\;

ww_d0(5) <= \d0[5]~output_o\;

ww_d0(4) <= \d0[4]~output_o\;

ww_d0(3) <= \d0[3]~output_o\;

ww_d0(2) <= \d0[2]~output_o\;

ww_d0(1) <= \d0[1]~output_o\;

ww_d0(0) <= \d0[0]~output_o\;

ww_d1(6) <= \d1[6]~output_o\;

ww_d1(5) <= \d1[5]~output_o\;

ww_d1(4) <= \d1[4]~output_o\;

ww_d1(3) <= \d1[3]~output_o\;

ww_d1(2) <= \d1[2]~output_o\;

ww_d1(1) <= \d1[1]~output_o\;

ww_d1(0) <= \d1[0]~output_o\;
END structure;


