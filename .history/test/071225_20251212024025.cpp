#include <iostream>
#include <vector>
#include <string>

class FSObject
{
protected:
    std::string name;

public:
    FSObject(const std::string &n) : name(n) {}
    virtual ~FSObject() {}

    virtual long getSize() const = 0;
    virtual std::string getName() const { return name; }

    virtual void print(int indent = 0) const = 0;
};
class File : public FSObject
{
private:
    long sizeKB;
    std::string type; // "text" or "binary"

public:
    File(const std::string &n, long s, const std::string &t)
        : FSObject(n), sizeKB(s), type(t) {}

    long getSize() const override { return sizeKB; }

    void print(int indent = 0) const override
    {
        std::cout << std::string(indent, ' ')
                  << "[FILE] " << name
                  << " (" << sizeKB << " KB, type=" << type << ")\n";
    }
};
class Shortcut : public FSObject
{
private:
    FSObject *target;

public:
    Shortcut(const std::string &n, FSObject *t)
        : FSObject(n), target(t) {}

    long getSize() const override
    {
        return 1; // fixed size = 1 KB
    }

    void print(int indent = 0) const override
    {
        std::cout << std::string(indent, ' ')
                  << "[SHORTCUT] " << name
                  << " -> " << target->getName()
                  << " (1 KB)\n";
    }
};
class Folder : public FSObject
{
private:
    std::vector<FSObject *> children;

public:
    Folder(const std::string &n) : FSObject(n) {}

    ~Folder()
    {
        for (auto c : children)
            delete c;
    }

    void add(FSObject *obj)
    {
        children.push_back(obj);
    }

    long getSize() const override
    {
        long total = 0;
        for (auto *obj : children)
            total += obj->getSize();
        return total;
    }

    void print(int indent = 0) const override
    {
        std::cout << std::string(indent, ' ')
                  << "[FOLDER] " << name
                  << " (size=" << getSize() << " KB)\n";

        for (auto *obj : children)
            obj->print(indent + 4);
    }
};
class Disk
{
private:
    std::string name;
    long capacityKB;
    Folder root;

public:
    Disk(const std::string &n, long cap)
        : name(n), capacityKB(cap), root("root") {}

    Folder &getRoot() { return root; }

    long getUsedSpace() const
    {
        return root.getSize();
    }

    long getFreeSpace() const
    {
        return capacityKB - getUsedSpace();
    }

    void printInfo() const
    {
        std::cout << "=== DISK: " << name << " ===\n";
        std::cout << "Capacity: " << capacityKB << " KB\n";
        std::cout << "Used:     " << getUsedSpace() << " KB\n";
        std::cout << "Free:     " << getFreeSpace() << " KB\n\n";
        root.print();
        std::cout << "=============================\n";
    }
};
int main()
{
    Disk disk("LocalDisk", 60000); // 60,000 KB (≈ 60MB)

    Folder &root = disk.getRoot();

    // FILES
    File *f1 = new File("report.txt", 1200, "text");
    File *f2 = new File("movie.bin", 25000, "binary");

    // FOLDER
    Folder *imgs = new Folder("Images");
    imgs->add(new File("cat.jpg", 800, "binary"));
    imgs->add(new File("dog.jpg", 900, "binary"));

    // SHORTCUT
    Shortcut *sc = new Shortcut("shortcut_to_report", f1);

    // add to root
    root.add(f1);
    root.add(f2);
    root.add(imgs);
    root.add(sc);

    // show info
    disk.printInfo();

    return 0;
}
