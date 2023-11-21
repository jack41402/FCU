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

-- DATE "11/22/2023 02:43:30"

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
	SW : IN std_logic_vector(9 DOWNTO 2);
	KEY : IN std_logic_vector(1 DOWNTO 0);
	HEX3 : BUFFER std_logic_vector(0 TO 6);
	HEX2 : BUFFER std_logic_vector(0 TO 6)
	);
END step2;

-- Design Ports Information
-- HEX3[6]	=>  Location: PIN_G15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX3[5]	=>  Location: PIN_D19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX3[4]	=>  Location: PIN_C19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX3[3]	=>  Location: PIN_B19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX3[2]	=>  Location: PIN_A19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX3[1]	=>  Location: PIN_F15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX3[0]	=>  Location: PIN_B18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX2[6]	=>  Location: PIN_F14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX2[5]	=>  Location: PIN_B17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX2[4]	=>  Location: PIN_A17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX2[3]	=>  Location: PIN_E15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX2[2]	=>  Location: PIN_B16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX2[1]	=>  Location: PIN_A16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX2[0]	=>  Location: PIN_D15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- KEY[1]	=>  Location: PIN_G3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SW[6]	=>  Location: PIN_H7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SW[7]	=>  Location: PIN_E3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SW[8]	=>  Location: PIN_E4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SW[9]	=>  Location: PIN_D2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- KEY[0]	=>  Location: PIN_H2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SW[2]	=>  Location: PIN_H6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SW[3]	=>  Location: PIN_G4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SW[4]	=>  Location: PIN_G5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SW[5]	=>  Location: PIN_J7,	 I/O Standard: 2.5 V,	 Current Strength: Default


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
SIGNAL ww_SW : std_logic_vector(9 DOWNTO 2);
SIGNAL ww_KEY : std_logic_vector(1 DOWNTO 0);
SIGNAL ww_HEX3 : std_logic_vector(0 TO 6);
SIGNAL ww_HEX2 : std_logic_vector(0 TO 6);
SIGNAL \HEX3[6]~output_o\ : std_logic;
SIGNAL \HEX3[5]~output_o\ : std_logic;
SIGNAL \HEX3[4]~output_o\ : std_logic;
SIGNAL \HEX3[3]~output_o\ : std_logic;
SIGNAL \HEX3[2]~output_o\ : std_logic;
SIGNAL \HEX3[1]~output_o\ : std_logic;
SIGNAL \HEX3[0]~output_o\ : std_logic;
SIGNAL \HEX2[6]~output_o\ : std_logic;
SIGNAL \HEX2[5]~output_o\ : std_logic;
SIGNAL \HEX2[4]~output_o\ : std_logic;
SIGNAL \HEX2[3]~output_o\ : std_logic;
SIGNAL \HEX2[2]~output_o\ : std_logic;
SIGNAL \HEX2[1]~output_o\ : std_logic;
SIGNAL \HEX2[0]~output_o\ : std_logic;
SIGNAL \KEY[1]~input_o\ : std_logic;
SIGNAL \SW[6]~input_o\ : std_logic;
SIGNAL \SW[8]~input_o\ : std_logic;
SIGNAL \SW[7]~input_o\ : std_logic;
SIGNAL \SW[9]~input_o\ : std_logic;
SIGNAL \WideOr6~0_combout\ : std_logic;
SIGNAL \HEX3~0_combout\ : std_logic;
SIGNAL \WideOr5~0_combout\ : std_logic;
SIGNAL \HEX3~1_combout\ : std_logic;
SIGNAL \WideOr4~0_combout\ : std_logic;
SIGNAL \HEX3~2_combout\ : std_logic;
SIGNAL \WideOr3~0_combout\ : std_logic;
SIGNAL \HEX3~3_combout\ : std_logic;
SIGNAL \WideOr2~0_combout\ : std_logic;
SIGNAL \HEX3~4_combout\ : std_logic;
SIGNAL \WideOr1~0_combout\ : std_logic;
SIGNAL \HEX3~5_combout\ : std_logic;
SIGNAL \WideOr0~0_combout\ : std_logic;
SIGNAL \HEX3~6_combout\ : std_logic;
SIGNAL \KEY[0]~input_o\ : std_logic;
SIGNAL \SW[5]~input_o\ : std_logic;
SIGNAL \SW[3]~input_o\ : std_logic;
SIGNAL \SW[2]~input_o\ : std_logic;
SIGNAL \SW[4]~input_o\ : std_logic;
SIGNAL \WideOr13~0_combout\ : std_logic;
SIGNAL \HEX2~0_combout\ : std_logic;
SIGNAL \WideOr12~0_combout\ : std_logic;
SIGNAL \HEX2~1_combout\ : std_logic;
SIGNAL \WideOr11~0_combout\ : std_logic;
SIGNAL \HEX2~2_combout\ : std_logic;
SIGNAL \WideOr10~0_combout\ : std_logic;
SIGNAL \HEX2~3_combout\ : std_logic;
SIGNAL \WideOr9~0_combout\ : std_logic;
SIGNAL \HEX2~4_combout\ : std_logic;
SIGNAL \WideOr8~0_combout\ : std_logic;
SIGNAL \HEX2~5_combout\ : std_logic;
SIGNAL \WideOr7~0_combout\ : std_logic;
SIGNAL \HEX2~6_combout\ : std_logic;

BEGIN

ww_SW <= SW;
ww_KEY <= KEY;
HEX3 <= ww_HEX3;
HEX2 <= ww_HEX2;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X39_Y29_N30
\HEX3[6]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \HEX3~0_combout\,
	devoe => ww_devoe,
	o => \HEX3[6]~output_o\);

-- Location: IOOBUF_X37_Y29_N30
\HEX3[5]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \HEX3~1_combout\,
	devoe => ww_devoe,
	o => \HEX3[5]~output_o\);

-- Location: IOOBUF_X37_Y29_N23
\HEX3[4]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \HEX3~2_combout\,
	devoe => ww_devoe,
	o => \HEX3[4]~output_o\);

-- Location: IOOBUF_X32_Y29_N2
\HEX3[3]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \HEX3~3_combout\,
	devoe => ww_devoe,
	o => \HEX3[3]~output_o\);

-- Location: IOOBUF_X32_Y29_N9
\HEX3[2]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \HEX3~4_combout\,
	devoe => ww_devoe,
	o => \HEX3[2]~output_o\);

-- Location: IOOBUF_X39_Y29_N16
\HEX3[1]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \HEX3~5_combout\,
	devoe => ww_devoe,
	o => \HEX3[1]~output_o\);

-- Location: IOOBUF_X32_Y29_N23
\HEX3[0]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \HEX3~6_combout\,
	devoe => ww_devoe,
	o => \HEX3[0]~output_o\);

-- Location: IOOBUF_X37_Y29_N2
\HEX2[6]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \HEX2~0_combout\,
	devoe => ww_devoe,
	o => \HEX2[6]~output_o\);

-- Location: IOOBUF_X30_Y29_N23
\HEX2[5]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \HEX2~1_combout\,
	devoe => ww_devoe,
	o => \HEX2[5]~output_o\);

-- Location: IOOBUF_X30_Y29_N16
\HEX2[4]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \HEX2~2_combout\,
	devoe => ww_devoe,
	o => \HEX2[4]~output_o\);

-- Location: IOOBUF_X30_Y29_N2
\HEX2[3]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \HEX2~3_combout\,
	devoe => ww_devoe,
	o => \HEX2[3]~output_o\);

-- Location: IOOBUF_X28_Y29_N2
\HEX2[2]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \HEX2~4_combout\,
	devoe => ww_devoe,
	o => \HEX2[2]~output_o\);

-- Location: IOOBUF_X30_Y29_N30
\HEX2[1]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \HEX2~5_combout\,
	devoe => ww_devoe,
	o => \HEX2[1]~output_o\);

-- Location: IOOBUF_X32_Y29_N30
\HEX2[0]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \HEX2~6_combout\,
	devoe => ww_devoe,
	o => \HEX2[0]~output_o\);

-- Location: IOIBUF_X0_Y23_N15
\KEY[1]~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_KEY(1),
	o => \KEY[1]~input_o\);

-- Location: IOIBUF_X0_Y25_N15
\SW[6]~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_SW(6),
	o => \SW[6]~input_o\);

-- Location: IOIBUF_X0_Y26_N1
\SW[8]~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_SW(8),
	o => \SW[8]~input_o\);

-- Location: IOIBUF_X0_Y26_N8
\SW[7]~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_SW(7),
	o => \SW[7]~input_o\);

-- Location: IOIBUF_X0_Y25_N1
\SW[9]~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_SW(9),
	o => \SW[9]~input_o\);

-- Location: LCCOMB_X31_Y28_N16
\WideOr6~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr6~0_combout\ = (\SW[6]~input_o\ & ((\SW[9]~input_o\) # (\SW[8]~input_o\ $ (\SW[7]~input_o\)))) # (!\SW[6]~input_o\ & ((\SW[7]~input_o\) # (\SW[8]~input_o\ $ (\SW[9]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101101111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW[6]~input_o\,
	datab => \SW[8]~input_o\,
	datac => \SW[7]~input_o\,
	datad => \SW[9]~input_o\,
	combout => \WideOr6~0_combout\);

-- Location: LCCOMB_X31_Y28_N2
\HEX3~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \HEX3~0_combout\ = (\KEY[1]~input_o\) # (!\WideOr6~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \KEY[1]~input_o\,
	datad => \WideOr6~0_combout\,
	combout => \HEX3~0_combout\);

-- Location: LCCOMB_X31_Y28_N28
\WideOr5~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr5~0_combout\ = (\SW[7]~input_o\ & (((!\SW[8]~input_o\ & !\SW[9]~input_o\)))) # (!\SW[7]~input_o\ & (\SW[6]~input_o\ & (\SW[8]~input_o\ $ (!\SW[9]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000100000110010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW[6]~input_o\,
	datab => \SW[8]~input_o\,
	datac => \SW[7]~input_o\,
	datad => \SW[9]~input_o\,
	combout => \WideOr5~0_combout\);

-- Location: LCCOMB_X31_Y28_N22
\HEX3~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \HEX3~1_combout\ = (\KEY[1]~input_o\) # (\WideOr5~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \KEY[1]~input_o\,
	datad => \WideOr5~0_combout\,
	combout => \HEX3~1_combout\);

-- Location: LCCOMB_X31_Y28_N0
\WideOr4~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr4~0_combout\ = (\SW[7]~input_o\ & (\SW[6]~input_o\ & ((!\SW[9]~input_o\)))) # (!\SW[7]~input_o\ & ((\SW[8]~input_o\ & ((!\SW[9]~input_o\))) # (!\SW[8]~input_o\ & (\SW[6]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000001010101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW[6]~input_o\,
	datab => \SW[8]~input_o\,
	datac => \SW[7]~input_o\,
	datad => \SW[9]~input_o\,
	combout => \WideOr4~0_combout\);

-- Location: LCCOMB_X31_Y28_N18
\HEX3~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \HEX3~2_combout\ = (\KEY[1]~input_o\) # (\WideOr4~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \KEY[1]~input_o\,
	datad => \WideOr4~0_combout\,
	combout => \HEX3~2_combout\);

-- Location: LCCOMB_X31_Y28_N20
\WideOr3~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr3~0_combout\ = (\SW[7]~input_o\ & ((\SW[6]~input_o\ & (\SW[8]~input_o\)) # (!\SW[6]~input_o\ & (!\SW[8]~input_o\ & \SW[9]~input_o\)))) # (!\SW[7]~input_o\ & (!\SW[9]~input_o\ & (\SW[6]~input_o\ $ (\SW[8]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001000010000110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW[6]~input_o\,
	datab => \SW[8]~input_o\,
	datac => \SW[7]~input_o\,
	datad => \SW[9]~input_o\,
	combout => \WideOr3~0_combout\);

-- Location: LCCOMB_X31_Y28_N30
\HEX3~3\ : cycloneiii_lcell_comb
-- Equation(s):
-- \HEX3~3_combout\ = (\KEY[1]~input_o\) # (\WideOr3~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \KEY[1]~input_o\,
	datad => \WideOr3~0_combout\,
	combout => \HEX3~3_combout\);

-- Location: LCCOMB_X31_Y28_N24
\WideOr2~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr2~0_combout\ = (\SW[8]~input_o\ & (\SW[9]~input_o\ & ((\SW[7]~input_o\) # (!\SW[6]~input_o\)))) # (!\SW[8]~input_o\ & (!\SW[6]~input_o\ & (\SW[7]~input_o\ & !\SW[9]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100010000010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW[6]~input_o\,
	datab => \SW[8]~input_o\,
	datac => \SW[7]~input_o\,
	datad => \SW[9]~input_o\,
	combout => \WideOr2~0_combout\);

-- Location: LCCOMB_X31_Y28_N10
\HEX3~4\ : cycloneiii_lcell_comb
-- Equation(s):
-- \HEX3~4_combout\ = (\KEY[1]~input_o\) # (\WideOr2~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \KEY[1]~input_o\,
	datad => \WideOr2~0_combout\,
	combout => \HEX3~4_combout\);

-- Location: LCCOMB_X31_Y28_N12
\WideOr1~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr1~0_combout\ = (\SW[7]~input_o\ & ((\SW[6]~input_o\ & ((\SW[9]~input_o\))) # (!\SW[6]~input_o\ & (\SW[8]~input_o\)))) # (!\SW[7]~input_o\ & (\SW[8]~input_o\ & (\SW[6]~input_o\ $ (\SW[9]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110010001001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW[6]~input_o\,
	datab => \SW[8]~input_o\,
	datac => \SW[7]~input_o\,
	datad => \SW[9]~input_o\,
	combout => \WideOr1~0_combout\);

-- Location: LCCOMB_X31_Y28_N14
\HEX3~5\ : cycloneiii_lcell_comb
-- Equation(s):
-- \HEX3~5_combout\ = (\KEY[1]~input_o\) # (\WideOr1~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \KEY[1]~input_o\,
	datad => \WideOr1~0_combout\,
	combout => \HEX3~5_combout\);

-- Location: LCCOMB_X31_Y28_N8
\WideOr0~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr0~0_combout\ = (\SW[8]~input_o\ & (!\SW[7]~input_o\ & (\SW[6]~input_o\ $ (!\SW[9]~input_o\)))) # (!\SW[8]~input_o\ & (\SW[6]~input_o\ & (\SW[7]~input_o\ $ (!\SW[9]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010100000000110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW[6]~input_o\,
	datab => \SW[8]~input_o\,
	datac => \SW[7]~input_o\,
	datad => \SW[9]~input_o\,
	combout => \WideOr0~0_combout\);

-- Location: LCCOMB_X31_Y28_N26
\HEX3~6\ : cycloneiii_lcell_comb
-- Equation(s):
-- \HEX3~6_combout\ = (\WideOr0~0_combout\) # (\KEY[1]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \WideOr0~0_combout\,
	datac => \KEY[1]~input_o\,
	combout => \HEX3~6_combout\);

-- Location: IOIBUF_X0_Y21_N8
\KEY[0]~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_KEY(0),
	o => \KEY[0]~input_o\);

-- Location: IOIBUF_X0_Y22_N15
\SW[5]~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_SW(5),
	o => \SW[5]~input_o\);

-- Location: IOIBUF_X0_Y23_N8
\SW[3]~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_SW(3),
	o => \SW[3]~input_o\);

-- Location: IOIBUF_X0_Y25_N22
\SW[2]~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_SW(2),
	o => \SW[2]~input_o\);

-- Location: IOIBUF_X0_Y27_N22
\SW[4]~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_SW(4),
	o => \SW[4]~input_o\);

-- Location: LCCOMB_X32_Y28_N24
\WideOr13~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr13~0_combout\ = (\SW[2]~input_o\ & ((\SW[5]~input_o\) # (\SW[3]~input_o\ $ (\SW[4]~input_o\)))) # (!\SW[2]~input_o\ & ((\SW[3]~input_o\) # (\SW[5]~input_o\ $ (\SW[4]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011110111101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW[5]~input_o\,
	datab => \SW[3]~input_o\,
	datac => \SW[2]~input_o\,
	datad => \SW[4]~input_o\,
	combout => \WideOr13~0_combout\);

-- Location: LCCOMB_X32_Y28_N10
\HEX2~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \HEX2~0_combout\ = (\KEY[0]~input_o\) # (!\WideOr13~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \KEY[0]~input_o\,
	datad => \WideOr13~0_combout\,
	combout => \HEX2~0_combout\);

-- Location: LCCOMB_X32_Y28_N12
\WideOr12~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr12~0_combout\ = (\SW[3]~input_o\ & (!\SW[5]~input_o\ & ((!\SW[4]~input_o\)))) # (!\SW[3]~input_o\ & (\SW[2]~input_o\ & (\SW[5]~input_o\ $ (!\SW[4]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010000001010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW[5]~input_o\,
	datab => \SW[3]~input_o\,
	datac => \SW[2]~input_o\,
	datad => \SW[4]~input_o\,
	combout => \WideOr12~0_combout\);

-- Location: LCCOMB_X32_Y28_N6
\HEX2~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \HEX2~1_combout\ = (\KEY[0]~input_o\) # (\WideOr12~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \KEY[0]~input_o\,
	datad => \WideOr12~0_combout\,
	combout => \HEX2~1_combout\);

-- Location: LCCOMB_X32_Y28_N0
\WideOr11~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr11~0_combout\ = (\SW[3]~input_o\ & (!\SW[5]~input_o\ & (\SW[2]~input_o\))) # (!\SW[3]~input_o\ & ((\SW[4]~input_o\ & (!\SW[5]~input_o\)) # (!\SW[4]~input_o\ & ((\SW[2]~input_o\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101000101110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW[5]~input_o\,
	datab => \SW[3]~input_o\,
	datac => \SW[2]~input_o\,
	datad => \SW[4]~input_o\,
	combout => \WideOr11~0_combout\);

-- Location: LCCOMB_X32_Y28_N2
\HEX2~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \HEX2~2_combout\ = (\KEY[0]~input_o\) # (\WideOr11~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \KEY[0]~input_o\,
	datad => \WideOr11~0_combout\,
	combout => \HEX2~2_combout\);

-- Location: LCCOMB_X32_Y28_N20
\WideOr10~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr10~0_combout\ = (\SW[3]~input_o\ & ((\SW[2]~input_o\ & ((\SW[4]~input_o\))) # (!\SW[2]~input_o\ & (\SW[5]~input_o\ & !\SW[4]~input_o\)))) # (!\SW[3]~input_o\ & (!\SW[5]~input_o\ & (\SW[2]~input_o\ $ (\SW[4]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000100011000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW[5]~input_o\,
	datab => \SW[3]~input_o\,
	datac => \SW[2]~input_o\,
	datad => \SW[4]~input_o\,
	combout => \WideOr10~0_combout\);

-- Location: LCCOMB_X32_Y28_N22
\HEX2~3\ : cycloneiii_lcell_comb
-- Equation(s):
-- \HEX2~3_combout\ = (\KEY[0]~input_o\) # (\WideOr10~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \KEY[0]~input_o\,
	datad => \WideOr10~0_combout\,
	combout => \HEX2~3_combout\);

-- Location: LCCOMB_X32_Y28_N8
\WideOr9~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr9~0_combout\ = (\SW[5]~input_o\ & (\SW[4]~input_o\ & ((\SW[3]~input_o\) # (!\SW[2]~input_o\)))) # (!\SW[5]~input_o\ & (\SW[3]~input_o\ & (!\SW[2]~input_o\ & !\SW[4]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000101000000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW[5]~input_o\,
	datab => \SW[3]~input_o\,
	datac => \SW[2]~input_o\,
	datad => \SW[4]~input_o\,
	combout => \WideOr9~0_combout\);

-- Location: LCCOMB_X32_Y28_N26
\HEX2~4\ : cycloneiii_lcell_comb
-- Equation(s):
-- \HEX2~4_combout\ = (\KEY[0]~input_o\) # (\WideOr9~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \KEY[0]~input_o\,
	datac => \WideOr9~0_combout\,
	combout => \HEX2~4_combout\);

-- Location: LCCOMB_X32_Y28_N28
\WideOr8~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr8~0_combout\ = (\SW[5]~input_o\ & ((\SW[2]~input_o\ & (\SW[3]~input_o\)) # (!\SW[2]~input_o\ & ((\SW[4]~input_o\))))) # (!\SW[5]~input_o\ & (\SW[4]~input_o\ & (\SW[3]~input_o\ $ (\SW[2]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001111010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW[5]~input_o\,
	datab => \SW[3]~input_o\,
	datac => \SW[2]~input_o\,
	datad => \SW[4]~input_o\,
	combout => \WideOr8~0_combout\);

-- Location: LCCOMB_X32_Y28_N14
\HEX2~5\ : cycloneiii_lcell_comb
-- Equation(s):
-- \HEX2~5_combout\ = (\KEY[0]~input_o\) # (\WideOr8~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \KEY[0]~input_o\,
	datad => \WideOr8~0_combout\,
	combout => \HEX2~5_combout\);

-- Location: LCCOMB_X32_Y28_N16
\WideOr7~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \WideOr7~0_combout\ = (\SW[5]~input_o\ & (\SW[2]~input_o\ & (\SW[3]~input_o\ $ (\SW[4]~input_o\)))) # (!\SW[5]~input_o\ & (!\SW[3]~input_o\ & (\SW[2]~input_o\ $ (\SW[4]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010000110010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SW[5]~input_o\,
	datab => \SW[3]~input_o\,
	datac => \SW[2]~input_o\,
	datad => \SW[4]~input_o\,
	combout => \WideOr7~0_combout\);

-- Location: LCCOMB_X32_Y28_N18
\HEX2~6\ : cycloneiii_lcell_comb
-- Equation(s):
-- \HEX2~6_combout\ = (\KEY[0]~input_o\) # (\WideOr7~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \KEY[0]~input_o\,
	datad => \WideOr7~0_combout\,
	combout => \HEX2~6_combout\);

ww_HEX3(6) <= \HEX3[6]~output_o\;

ww_HEX3(5) <= \HEX3[5]~output_o\;

ww_HEX3(4) <= \HEX3[4]~output_o\;

ww_HEX3(3) <= \HEX3[3]~output_o\;

ww_HEX3(2) <= \HEX3[2]~output_o\;

ww_HEX3(1) <= \HEX3[1]~output_o\;

ww_HEX3(0) <= \HEX3[0]~output_o\;

ww_HEX2(6) <= \HEX2[6]~output_o\;

ww_HEX2(5) <= \HEX2[5]~output_o\;

ww_HEX2(4) <= \HEX2[4]~output_o\;

ww_HEX2(3) <= \HEX2[3]~output_o\;

ww_HEX2(2) <= \HEX2[2]~output_o\;

ww_HEX2(1) <= \HEX2[1]~output_o\;

ww_HEX2(0) <= \HEX2[0]~output_o\;
END structure;


