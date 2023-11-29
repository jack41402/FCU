library verilog;
use verilog.vl_types.all;
entity step2 is
    port(
        SW              : in     vl_logic_vector(9 downto 2);
        KEY             : in     vl_logic_vector(1 downto 0);
        HEX3            : out    vl_logic_vector(0 to 6);
        HEX2            : out    vl_logic_vector(0 to 6)
    );
end step2;
