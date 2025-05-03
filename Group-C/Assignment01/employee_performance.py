def ask_question(question: str) -> str:
    response = input(question + " ").lower().strip()
    return response

def evaluate_performance():
    print("📊 Welcome to the Employee Performance Expert System\n")

    punctuality = ask_question("How is the employee's punctuality? (excellent/good/poor)")
    task_completion = ask_question("Are tasks completed on time? (yes/no)")
    teamwork = ask_question("How is the teamwork quality? (excellent/good/poor)")
    innovation = ask_question("Does the employee show innovation? (yes/no)")
    communication = ask_question("How are the communication skills? (excellent/good/poor)")

    # Rule-based evaluation
    if (
        punctuality == "excellent"
        and task_completion == "yes"
        and teamwork == "excellent"
        and innovation == "yes"
        and communication == "excellent"
    ):
        print("\n🏆 Performance Evaluation: OUTSTANDING")
    elif (
        punctuality in ["excellent", "good"]
        and task_completion == "yes"
        and teamwork in ["excellent", "good"]
        and communication in ["excellent", "good"]
    ):
        print("\n✅ Performance Evaluation: GOOD")
    elif (
        punctuality == "poor"
        or task_completion == "no"
        or teamwork == "poor"
        or communication == "poor"
    ):
        print("\n⚠️ Performance Evaluation: NEEDS IMPROVEMENT")
    else:
        print("\n🔍 Performance Evaluation: AVERAGE – Monitor and provide feedback.")

# Run the expert system
if __name__ == "__main__":
    evaluate_performance()
