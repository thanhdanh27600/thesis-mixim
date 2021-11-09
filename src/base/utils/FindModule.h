#ifndef FIND_MODULE_H
#define FIND_MODULE_H

#include <omnetpp.h>

/**
 * @brief Provides method templates to find omnet modules.
 *
 * @ingroup baseUtils
 * @ingroup utils
 */
template<typename T = cModule * const >
class FindModule
{
    public:
        /**
         * @brief Returns a pointer to a sub module of the passed module with
         * the type of this template.
         *
         * Returns NULL if no matching submodule could be found.
         */
        static T findSubModule(const cModule * const top)
        {
            for (cModule::SubmoduleIterator i(top); !i.end(); i++)
            {
                cModule * const sub = i();
                // this allows also a return type of read only pointer: const cModule *const
                T dCastRet = dynamic_cast<T>(sub);
                if (dCastRet != NULL)
                    return dCastRet;
                // this allows also a return type of read only pointer: const cModule *const
                T recFnd = findSubModule(sub);
                if (recFnd != NULL)
                    return recFnd;
            }
            return NULL;
        }

        /**
         * @brief Returns a pointer to the module with the type of this
         * template.
         *
         * Returns NULL if no module of this type could be found.
         */
        static T findGlobalModule()
        {
            return findSubModule(simulation.getSystemModule());
        }

        /**
         * @brief Returns a pointer to the host module of the passed module.
         *
         * Assumes that every host module is a direct sub module of the
         * simulation.
         */
        static cModule* findHost(cModule * const m)
        {
            cModule* parent = m != NULL ? m->getParentModule() : NULL;
            cModule* node = m;

            // all nodes should be a sub module of the simulation which has no parent module!!!
            while (parent != NULL && parent->getParentModule() != NULL)
            {
                node = parent;
                parent = node->getParentModule();
            }
            return node;
        }
        static cModule* findNetwork(cModule * const m)
        {
            cModule* node = findHost(m);

            return node ? node->getParentModule() : node;
        }
        // the constness version
        static const cModule* findHost(const cModule * const m)
        {
            const cModule* parent = m != NULL ? m->getParentModule() : NULL;
            const cModule *node = m;

            // all nodes should be a sub module of the simulation which has no parent module!!!
            while (parent != NULL && parent->getParentModule() != NULL)
            {
                node = parent;
                parent = node->getParentModule();
            }
            return node;
        }
        static const cModule* findNetwork(const cModule * const m)
        {
            const cModule* node = findHost(m);

            return node ? node->getParentModule() : node;
        }
};

/**
 * @brief Finds and returns the pointer to a module of type T.
 * Uses FindModule<>::findSubModule(), FindModule<>::findHost(). See usage e.g. at ConnectionManagerAccess.
 */
template<typename T = cModule>
class AccessModuleWrap
{
    public:
        typedef T wrapType;
    private:
        T* pModule;
        /** @brief Copy constructor is not allowed.
         */
        AccessModuleWrap(const AccessModuleWrap<T>&);
        /** @brief Assignment operator is not allowed.
         */
        AccessModuleWrap<T>& operator=(const AccessModuleWrap<T>&);

    public:
        AccessModuleWrap() :
                pModule(NULL)
        {
        }

        virtual ~AccessModuleWrap()
        {
        }
        ;

        T* get(cModule * const from = NULL)
        {
            if (!pModule)
            {
                pModule = FindModule<T*>::findSubModule(
                        FindModule<>::findHost(from != NULL ? from : simulation.getContextModule()));
            }
            return pModule;
        }
};

#endif
