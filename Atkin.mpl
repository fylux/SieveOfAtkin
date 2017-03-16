Primes:=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59]:
L:=1000;
S:=[1,7,11,13,17,19,23,29,31,37,41,43,47,49,53,59];
W:=[seq(i,i=1..ceil(L/60)-1)]:

for w in W do
	for s in S do
		n:=60*w+s;
		a:=0;

 		########3.1
		if modp(s,4)=1 then  
			for x from 1 to ceil(sqrt(n)/2) do
				for y from 1 to ceil(sqrt(n)) do 
					if 4*x^2+y^2=n then a:=1-a;end if;
				end do;
			end do;
		end if;

		########3.2
		if modp(s,6)=1 and modp(s,4)<>1 then  
			for x from 1 to ceil(sqrt(n/3)) do
				for y from 1 to ceil(sqrt(n)) do 
					if 3*x^2+y^2=n then a:=1-a;end if;
				end do;
			end do;
		end if;

		########3.3
		if modp(s,12)=11 and modp(s,6)<>1 and modp(s,4)<>1 then  
			for x from 2 to n do  
				for y from 1 to x-1 do
					if 3*x^2-y^2=n then a:=1-a;end if;
				end do;
			end do;
		 end if;

		##### squares
		if a=1 then 
			for q in Primes while q^2<=n and a=1 do if irem(n,q^2)=0 then a:=0;fi;end do;
		end if;

		if a=1 then Primes:=[op(Primes),n]; end if;  
		end do;
end do;