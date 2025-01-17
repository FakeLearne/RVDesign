riscv64-unknown-elf-as -mabi=ilp32 -march=rv32i ./1-test-mov.tile-toIntReg.s -o ./1-test-mov.tile-toIntReg.elf
riscv64-unknown-linux-gnu-objdump -d ./1-test-mov.tile-toIntReg.elf > ./1-test-mov.tile-toIntReg.lst
riscv64-unknown-linux-gnu-objcopy -O verilog --only-section ".text*"  ./1-test-mov.tile-toIntReg.elf --set-start=0x0 ../../../rom/test_program.hex
riscv64-unknown-linux-gnu-objcopy -O verilog --only-section ".data*" --only-section ".rodata*" ./1-test-mov.tile-toIntReg.elf --set-start=0x0 ../../../rom/test_data.hex
echo "Success!"
