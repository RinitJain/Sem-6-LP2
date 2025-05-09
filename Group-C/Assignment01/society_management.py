def ask_yes_no(question: str) -> bool:
    response = input(question + " (yes/no): ").strip().lower()
    return response == 'yes'


def explain_water_issue():
    print("\n🚰 Diagnosing Water Supply Issue on Monday:")
    maintenance_on_monday = ask_yes_no("Was the water pump under maintenance on Monday?")
    tank_empty = ask_yes_no("Was the water tank empty?")
    pump_faulty = ask_yes_no("Was the water pump faulty?")
    power_cut = ask_yes_no("Was there a power cut affecting the pump?")
    backup_available = ask_yes_no("Was there a generator or backup available for the pump?")

    if maintenance_on_monday:
        return "📝 Reason: No water on Monday due to scheduled pump maintenance."
    elif tank_empty and pump_faulty:
        return "📝 Reason: No water on Monday due to an empty tank and faulty pump."
    elif power_cut and not backup_available:
        return "📝 Reason: No water due to power outage and no backup system."
    else:
        return "📝 Reason: The cause of water outage is unclear. Please check logs."


def explain_lighting_issue():
    print("\n💡 Diagnosing Lighting Issue in Common Passage:")
    power_outage = ask_yes_no("Was there a power outage?")
    backup_power = ask_yes_no("Was backup lighting available?")
    bulb_damaged = ask_yes_no("Were the common area bulbs or fittings damaged?")
    electrician_available = ask_yes_no("Was the electrician available for repairs?")
    switchboard_faulty = ask_yes_no("Was the switchboard or fuse damaged?")

    if power_outage and not backup_power:
        return "📝 Reason: No lights in common passage due to power outage and no backup lighting."
    elif bulb_damaged and not electrician_available:
        return "📝 Reason: No lights due to damaged bulbs and unavailable electrician."
    elif switchboard_faulty:
        return "📝 Reason: No lights due to faulty switchboard or blown fuse."
    else:
        return "📝 Reason: Lighting issue cause is uncertain. Further investigation needed."


def main():
    print("🏘️ Society Maintenance Expert System")
    print("-------------------------------------")
    while True:
        print("\nChoose an option:")
        print("1. Diagnose water supply issue on Monday")
        print("2. Diagnose lighting issue in common passage")
        print("3. Exit")

        choice = input("Enter your choice (1-3): ").strip()

        if choice == '1':
            reason = explain_water_issue()
            print(reason)
        elif choice == '2':
            reason = explain_lighting_issue()
            print(reason)
        elif choice == '3':
            print("👋 Exiting the expert system. Thank you!")
            break
        else:
            print("⚠️ Invalid choice. Please enter 1, 2, or 3.")

if __name__ == "__main__":
    main()
