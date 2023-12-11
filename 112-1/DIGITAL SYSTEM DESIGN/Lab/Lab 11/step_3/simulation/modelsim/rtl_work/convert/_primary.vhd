library verilog;
use verilog.vl_types.all;
entity convert is
    port(
        number          : in     vl_logic_vector(3 downto 0);
        led             : out    vl_logic_vector(0 to 6)
    );
end convert;
