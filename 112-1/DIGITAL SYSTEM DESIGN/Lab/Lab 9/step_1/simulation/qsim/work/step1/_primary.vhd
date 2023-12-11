library verilog;
use verilog.vl_types.all;
entity step1 is
    port(
        v               : in     vl_logic_vector(3 downto 0);
        d0              : out    vl_logic_vector(0 to 6);
        d1              : out    vl_logic_vector(0 to 6)
    );
end step1;
