library verilog;
use verilog.vl_types.all;
entity step_3 is
    port(
        EO              : in     vl_logic;
        clk             : in     vl_logic;
        reset           : in     vl_logic;
        led             : out    vl_logic_vector(0 to 6)
    );
end step_3;
