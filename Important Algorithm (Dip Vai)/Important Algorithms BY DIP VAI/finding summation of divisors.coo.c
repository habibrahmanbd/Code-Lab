        if (N < 2) return -1;
        long long d = N;
        for (long long i=2; i*i<=N; ++i) if (N%i==0) { d=i; break; }

        long long answer = d + (4*d-5)*N;
        if (d==N) {
            for (long long i=2; (N+i-1)/i >= 1000000; ++i) answer += (N+i-1)/i;
            for (long long y=min(N-1,999999LL); y>=2; --y) answer += y*( (N+y-2)/(y-1) - (N+y-1)/y );
            answer += 1; // last iteration
        } else {
            for (long long i=2; i<=d; ++i) answer += (N+i-1)/i;
        }
        return answer;
    }
