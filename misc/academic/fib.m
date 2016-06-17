% fib.m
% solution to the fibonacci discrete-time linear system.
% Author: Ronny Macmaster

% fib[1] = 0, fib[2] = 1
% fib[n] = fib[n-2] + fib[n-1]
% O(1) Solution? (power func is probably not O(1))
function n = fib(n)
    % vars
    c1 = 2/(5+sqrt(5));
    c2 = 2/(5-sqrt(5));
    g1 = (1+sqrt(5))/2;
    g2 = (1-sqrt(5))/2;
    
    % fib[n] = c1*g1^n + c2*g2^n
    n = c1*g1**n + c2*g2**n;
end

% optional user prompt

n = 0;
while(n >= 0)
     n = input("which fib number? ");
     % n = sscanf(n, "%d")
     fn = fib(n)
end