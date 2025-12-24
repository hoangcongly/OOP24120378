#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell
{
public:
    virtual ~Spell() = default;
    virtual int getPower() const = 0;
    virtual Spell *clone() const = 0;
};

class Fireball : public Spell
{
public:
    int getPower() const override
    {
        return 30;
    }
    Spell *clone() const override
    {
        return new Fireball(*this);
    }
};

class Healing : public Spell
{
public:
    int getPower() const override
    {
        return 20;
    }
    Spell *clone() const override
    {
        return new Healing(*this);
    }
};

class Unit
{
private:
    string name;
    int weaponPower;
    Spell *spell;

public:
    Unit(const string &n, int wp)
    {
        name = n;
        weaponPower = wp;
        spell = nullptr;
    }
    Unit(const Unit &other)
    {
        name = other.name + "_clone";
        weaponPower = other.weaponPower;
        if (other.spell != nullptr)
        {
            spell = other.spell->clone();
        }
        else
            spell = nullptr;
    }
    void learnSpell(Spell *s)
    {
        if (spell != nullptr)
        {
            delete spell;
        }
        spell = s;
    }
    int totalPower() const
    {
        if (spell != nullptr)
        {
            return weaponPower + spell->getPower();
        }
        return weaponPower;
    }
    void print() const
    {
        cout << "Unit: " << name
             << " | Weapon: " << weaponPower
             << " | Total Power: " << totalPower()
             << endl;
    }
    ~Unit()
    {
        delete spell;
        cout << name << " destroyed" << endl;
    }
};

class MagicGuild
{
private:
    vector<Unit *> members;

public:
    void add(Unit *u)
    {
        members.push_back(u);
    }
    void update() const
    {
        cout << "=== Magic Guild Update ===" << endl;
        for (auto m : members)
        {
            m->print();
        }
    }
};

int main()
{
    cout << "===== STEP 1: UNIT LEARNS SPELL =====" << endl;

    // Tạo unit + học phép
    Unit soldier("Soldier", 40);
    soldier.learnSpell(new Fireball());
    soldier.print();

    cout << "\n===== STEP 2: DEEP COPY UNIT =====" << endl;

    // Sao chép độc lập
    Unit clone = soldier;
    clone.learnSpell(new Healing());

    cout << "Original Unit:" << endl;
    soldier.print();

    cout << "Cloned Unit:" << endl;
    clone.print();

    cout << "\n===== STEP 3: MAGIC GUILD =====" << endl;

    // Magic Guild
    MagicGuild guild;
    guild.add(&soldier);
    guild.add(&clone);
    guild.update();

    cout << "\n===== STEP 4: OBJECT LIFECYCLE =====" << endl;

    {
        MagicGuild tempGuild;
        tempGuild.add(&soldier);
        tempGuild.update();
    } // tempGuild bị hủy, soldier vẫn tồn tại

    cout << "\n===== END PROGRAM =====" << endl;
    return 0;
}