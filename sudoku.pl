print "sudoku";

system "./sudoku";
system "minisat sudokuCNF.cnf result";

open(fh, "result") || die "Cannot open result file.\n";
$subadd = <fh>;
@val = <fh>;
close(fh);

@val2 = split(' ', @val[0]);

for($i=0; $i<9; $i++) {
	for($j=0; $j<9; $j++) {
		for($k=0; $k<9; $k++) {
			$res = $i*81 + $j*9 + $k;
			
			if(@val2[$res] > 0) {
				$las = @val2[$res];
				if($las%9 == 0) {
					print $las%9+9, " ";
				}else {
					print $las%9, " "; 
				}
			}
		}

	}
	print "\n";
}
