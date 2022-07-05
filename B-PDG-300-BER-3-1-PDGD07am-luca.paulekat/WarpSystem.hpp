#ifndef WarpSystem_hpp_
    #define WarpSystem_hpp_

namespace WarpSystem
{
    class QuantumReactor {
        public:
            bool _stability = true;
            bool isStable ();
            void setStability(bool stability);
    };
    class Core {
        public:
            QuantumReactor *_coreReactor;
            Core(QuantumReactor *coreReactor);
            QuantumReactor *checkReactor();
    };
}

#endif