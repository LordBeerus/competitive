//maximize     c^T x
//     subject to   Ax <= b
//                  x >= 0
//
// INPUT: A -- an m x n matrix
//        b -- an m-dimensional vector
//        c -- an n-dimensional vector
//        x -- a vector where the optimal solution will be stored
//
// OUTPUT: value of the optimal solution (infinity if unbounded
//         above, nan if infeasible)
//
struct Simplex {
  
 	set<int> N;
 	set<int> B;
	double b[maxn + maxm];
	double A[maxn + maxm][maxn + maxm];
	double c[maxn + maxm];
	double v;

	int n, m;
 //n = total variables
 //m = total eqauations
	double c_backup[maxn + maxm];
	int init(double _A[maxm][maxn], double _b[maxm], double _c[maxn], int _n, int _m) {
		N.clear(); B.clear();
		n = _n; m = _m;

		for (int j = 0; j < n; j++) N.insert(j);
		for (int i = n; i < n + m; i++) B.insert(i);
		for (int i = n; i < n + m; i++) b[i] = _b[i - n];
		memset(A, 0, sizeof(A));
		for (int i = n; i < n + m; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = _A[i - n][j];
		for (int j = 0; j < n; j++) c[j] = _c[j];
		v = 0;

		// find feasible solution
		int l = n;
		for (int i = n + 1; i < n + m; i++)
			if (b[i] < b[l]) l = i;
		if (sig(b[l]) < 0) {
			// add one dimension
			N.insert(n + m);
			memcpy(c_backup, c, sizeof(c));
			memset(c, 0, sizeof(c));
			c[n + m] = -1;
			for (int i = n; i < n + m; i++) A[i][n + m] = -1;
			pivot(n + m, l);
			double r = work();
			if (sig(r) != 0)
				return -1; // no solution
			
			// x[n + m] <= 0
			B.insert(n + m + 1);
			if (N.find(n + m) != N.end()) {
				A[n + m + 1][n + m] = 1.0;
			} else {
				FOREACH(j, N) A[n + m + 1][*j] = -A[n + m][*j];	
				b[n + m + 1] = -b[n + m];
			}
			// restore c and make it valid
			memcpy(c, c_backup, sizeof(c));
			for (int i = 0; i < n; i++)
			if (B.find(i) != B.end()) {
				// 非基本变量i 已经变成 基本变量了, 那么ci需change
				v += c[i] * b[i];
				FOREACH(j, N) c[*j] -= c[i] * A[i][*j];
				c[i] = 0.0;
			}
		}
		return 0;
	}

	void pivot(int e, int l) {
		static int que[maxn], qr;
		A[e][l] = 1.0 / A[l][e];
		qr = 0;
		// opt.3 A[l][*j] != 0
		FOREACH(j, N) if (*j != e && sig(A[l][*j])) A[e][*j] = A[l][*j] / A[l][e], que[qr++] = *j;
		b[e] = b[l] / A[l][e];
		memset(A[l], 0, sizeof(A[l]));
		b[l] = 0;

		B.erase(l); B.insert(e);
		N.erase(e); N.insert(l);
		que[qr++] = l;
		// opt.2 A[i][e] != 0, 920ms -> 623ms
		FOREACH(_i, B) if (*_i != e && sig(A[*_i][e])) {
			int i = *_i;
			b[i] = b[i] - A[i][e] * b[e];
			for (int qi = 0; qi < qr; qi++) {
				int j = que[qi];
				A[i][j] -= A[i][e] * A[e][j];
			}
			A[i][e] = 0.0;
		}

		v += c[e] * b[e];
		FOREACH(j, N) c[*j] -= c[e] * A[e][*j];
		c[e] = 0.0;
	}

	double work() {
		while (1) {
			int e = -1; // 非基本变量 -> 基本变量
			double maxc = -INF;
			// opt.1 find max c, 951ms->920ms
			FOREACH(j, N) if (c[*j] > maxc) {
				maxc = c[*j];
				e = *j;
			}
			if (sig(maxc) <= 0)
				break;
			double delta = INF;
			int l; // 基本变量 -> 非基本变量
			FOREACH(_i, B) {
				int i = *_i;
				if (sig(A[i][e]) > 0) {
					double t_delta = b[i] / A[i][e];
					if (delta > t_delta) {
						delta = t_delta;
						l = i;
					}
				}
			}
			if (delta == INF) 
				return INF;
			pivot(e, l);
//FOREACH(i, N) printf("%d ", *i);
//puts("");
		}
		return v;
	}
} simplex;

