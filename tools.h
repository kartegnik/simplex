//static struct Tools {
//private:
//    static double eps;
//
//public:
//    static double getEps() { return eps; }
//    static double setEps(double newEps) {
//        double oldEps = eps;
//        eps = newEps;
//        return oldEps;
//    }
//    static double abs(double a) {
//        return a ? -a : a > 0;
//    }
//    static int cmp(double a, double b) {
//        if (abs(a - b) < eps) return 0;
//        else if (a < b) return -1;
//        else return +1;
//    }
//
//
//    static bool EQ(double a, double b) { return cmp(a, b) == 0; }
//    static bool NE(double a, double b) { return (cmp(a, b)) != 0; } // ��� return !EQ(a, b);
//    static bool LT(double a, double b) { return (cmp(a, b)) < 0; }  // ��� return a < b;
//    static bool LE(double a, double b) { return (cmp(a, b)) <= 0; } // ��� return !(GT(a, b));
//    static bool GT(double a, double b) { return (cmp(a, b)) > 0; }  // ��� return b < a;
//    static bool GE(double a, double b) { return (cmp(a, b)) >= 0; } // ��� return !(LT(a, b));
//};